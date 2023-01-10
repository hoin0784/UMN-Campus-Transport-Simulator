#ifndef LIBS_TRANSIT_INCLUDE_ITRANSENTITY_H_
#define LIBS_TRANSIT_INCLUDE_ITRANSENTITY_H_

#include <vector>
#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "CSVHandler.h"

/**
 * @brief Transport Entity abstraction, used with drone, car, and helicopter
 * @brief ITransEntity move using euler integration based on a specified
 * @brief velocity and direction.
 */
class ITransEntity : public IEntity {
 public:
  /**
   * @brief Construct a new ITransEntity object
   * 
   * @param obj contains details about the transport entity
   */
  ITransEntity(const JsonObject& obj);
  /**
   * @brief Destroy the ITransEntity object
   * 
   */
  ~ITransEntity();

  float GetSpeed() const { return speed; }
  /**
   * @brief Get the Position of the transport entity
   * 
   * @return Vector3 
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Get the Direction of the transport entity
   * 
   * @return Vector3 
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Get the Destination of the transport entity
   * 
   * @return Vector3 
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Get the Details of the transport entity
   * 
   * @return JsonObject 
   */
  JsonObject GetDetails() const { return details; }
  /**
   * @brief Get the Pickup Vehicle of the transport entity (returns NULL only)
   * 
   * @return std::string 
   */
  std::string GetPickupVehicle() const { return NULL; }
  /**
   * @brief Get the Vehicle Type of the transport entity (car, helicopter, or drone)
   * 
   * @return std::string 
   */
  std::string GetVehicleType() const { return vehicleType; }
  /**
   * @brief Get the Availability of the transport entity
   * 
   * @return true if not busy
   * @return false if moving a robot or on the way to one
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Get the Nearest robot to move next
   * 
   * @param scheduler vector containing robots scheduled in the system
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);
  /**
   * @brief Updates the ITransEntity's position
   */ 
  void Update(double dt, std::vector<IEntity*> scheduler);
  /**
   * @brief Set the Position of the transport entity
   * 
   * @param pos_ 
   */
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Set the Direction of the transport entity
   * 
   * @param dir_ 
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Set the Destination of the transport entity
   * 
   * @param des_ 
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Rotates the transport entity by angle
   * 
   * @param angle
   */
  void Rotate(double angle);
  /**
   * @brief makes the transport entity jump by height
   * 
   * @param height 
   */
  void Jump(double height);
  /**
   * @brief Removing the copy constructor and assignment operator
   * @brief so that ITransEntity cannot be copied.
   */ 
  ITransEntity(const ITransEntity& ITransEntity) = delete;
  /**
   * @brief Removing the Assignment opterator so ITransEntities cannot be reassigned
   * 
   * @param ITransEntity 
   * @return ITransEntity& 
   */
  ITransEntity& operator=(const ITransEntity& ITransEntity) = delete;

 protected:
  /**
  * @brief Helper function to set the strategies of the car
  * 
  */
  virtual void SetStrategies() = 0;
  // Previously private variables are now protected due to
  // new level of abstraction
  IEntity* nearestEntity = NULL;
  IStrategy* toTargetPosStrategy = NULL;
  IStrategy* toTargetDestStrategy = NULL;
  std::string strategyName;
  Vector3 destination;


 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  float jumpHeight = 0;
  bool goUp = true;  // jump helper
  float speed;
  bool available;
  bool pickedUp;
  std::string vehicleType;
  float distanceTraveled;  // distance traveled by the robot
  double endTime;
  CSVHandler* csvInstance;
};

#endif  // LIBS_TRANSIT_INCLUDE_ITRANSENTITY_H_
