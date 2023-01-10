#ifndef LIBS_TRANSIT_INCLUDE_IENTITY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITY_H_
/**
 * include
 */
#include <vector>
#include "graph.h"
#include "math/vector3.h"
#include "util/json.h"

using namespace routing;

/**
 * @brief Controller Interface
 * @brief Abstract controller class used in the Transit Service. Uses the Model View
 * @brief Controller Pattern.
 */
class IEntity {
 public:
  /**
   * @brief Construct a new IEntity object
   * 
   */
  IEntity() {
    static int currentId = 0;
    id = currentId;
    currentId++;
  }
  /**
   * @brief Destroy the IEntity object
   * 
   */
  virtual ~IEntity() {}
  /**
   * @brief Get the Id of the entity
   * 
   * @return int 
   */
  virtual int GetId() const { return id; }
  /**
   * @brief Get the Position of the entity
   * 
   * @return Vector3 
   */
  virtual Vector3 GetPosition() const = 0;
  /**
   * @brief Get the Direction of the entity
   * 
   * @return Vector3 
   */
  virtual Vector3 GetDirection() const = 0;
  /**
   * @brief Get the Destination of the entity
   * 
   * @return Vector3 
   */
  virtual Vector3 GetDestination() const = 0;
  /**
   * @brief Get the Details of the entity
   * 
   * @return JsonObject 
   */
  virtual JsonObject GetDetails() const = 0;
  /**
   * @brief Get the Pickup Vehicle of the entity (NULL if transport vehicle)
   * 
   * @return std::string 
   */
  virtual std::string GetPickupVehicle() const = 0;
  /**
   * @brief Get the Speed object
   * 
   * @return float 
   */
  virtual float GetSpeed() const = 0;
  /**
   * @brief Get the Availability of the entity
   * 
   * @return true 
   * @return false 
   */
  virtual bool GetAvailability() const {}
  /**
   * @brief Get the Strategy the entity will take
   * 
   * @return std::string 
   */
  virtual std::string GetStrategyName() {}
  /**
   * @brief Set the Availability of the entity
   * 
   * @param choice 
   */
  virtual void SetAvailability(bool choice) {}
  /**
   * @brief Updates the entity (called very frequently)
   * 
   * @param dt time since last update
   * @param scheduler scheduler containing entities in the system
   */
  virtual void Update(double dt, std::vector<IEntity*> scheduler) {}
  /**
   * @brief Set the Graph object
   * 
   * @param graph graph used for pathing algorithms
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Set the Position of the entity
   * 
   * @param pos_ 
   */
  virtual void SetPosition(Vector3 pos_) {}
  /**
   * @brief Set the Direction of the entity
   * 
   * @param dir_ 
   */
  virtual void SetDirection(Vector3 dir_) {}
  /**
   * @brief Set the Destination of the entity
   * 
   * @param des_ 
   */
  virtual void SetDestination(Vector3 des_) {}
  /**
   * @brief Set the Strategy Name that the entity will take
   * 
   * @param strategyName_ 
   */
  virtual void SetStrategyName(std::string strategyName_) {}
  /**
   * @brief Rotates the entity by angle
   * 
   * @param angle angle to rotate the entity
   */
  virtual void Rotate(double angle) {}
  /**
   * @brief Jumps the entity by height
   * 
   * @param height for the entity to jump
   */
  virtual void Jump(double height) {}


 protected:
  int id;
  const IGraph* graph;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITY_H_
