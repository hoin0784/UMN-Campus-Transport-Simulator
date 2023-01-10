#define _USE_MATH_DEFINES
#include "ITransEntity.h"
#include "CSVHandler.h"

#include <cmath>
#include <limits>

ITransEntity::ITransEntity(const JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  vehicleType = (std::string)obj["type"];

  available = true;
  endTime = 0;
  csvInstance = CSVHandler::GetInstance();
}

ITransEntity::~ITransEntity() {
  // Delete dynamically allocated variables
}

void ITransEntity::GetNearestEntity(std::vector<IEntity*> scheduler) {
  float minDis = std::numeric_limits<float>::max();
  for (auto entity : scheduler) {
    if (entity->GetAvailability()) {
      float disToEntity = this->position.Distance(entity->GetPosition());
      if (disToEntity <= minDis) {
        if (entity->GetPickupVehicle() == GetVehicleType()) {
          minDis = disToEntity;
          nearestEntity = entity;
        }
      }
    }
  }

  if (nearestEntity) {
    nearestEntity->SetAvailability(false);
    available = false;
    pickedUp = false;
    destination = nearestEntity->GetPosition();
    distanceTraveled = GetPosition().Distance(destination);
    strategyName = nearestEntity->GetStrategyName();
    SetStrategies();  // declared in subclasses
  }
}



void ITransEntity::Update(double dt, std::vector<IEntity*> scheduler) {
  if (available) {
    GetNearestEntity(scheduler);
  }

  if (toTargetPosStrategy) {
    toTargetPosStrategy->Move(this, dt);
    if (toTargetPosStrategy->IsCompleted()) {
      delete toTargetPosStrategy;
      toTargetPosStrategy = NULL;
    }
  } else if (toTargetDestStrategy) {
    endTime += dt;
    toTargetDestStrategy->Move(this, dt);

    // Moving the robot
    nearestEntity->SetPosition(this->GetPosition());
    nearestEntity->SetDirection(this->GetDirection());
    if (toTargetDestStrategy->IsCompleted()) {
        csvInstance->
        writeData(details, endTime, strategyName, distanceTraveled);

        endTime = 0;
        Vector3 groundPos =
        Vector3(this->GetPosition().x, 254, this->GetPosition().z);

        nearestEntity->SetPosition(groundPos);

        delete toTargetDestStrategy;
        toTargetDestStrategy = NULL;
        available = true;
        nearestEntity = NULL;
    }
  }
}

void ITransEntity::Rotate(double angle) {
  Vector3 dirTmp = direction;
  direction.x = dirTmp.x * std::cos(angle) - dirTmp.z * std::sin(angle);
  direction.z = dirTmp.x * std::sin(angle) + dirTmp.z * std::cos(angle);
}

void ITransEntity::Jump(double height) {
  if (goUp) {
    position.y += height;
    jumpHeight += height;
    if (jumpHeight > 5) {
      goUp = false;
    }
  } else {
    position.y -= height;
    jumpHeight -= height;
    if (jumpHeight < 0) {
      goUp = true;
    }
  }
}
