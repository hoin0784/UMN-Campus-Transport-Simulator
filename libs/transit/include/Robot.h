#ifndef LIBS_TRANSIT_INCLUDE_ROBOT_H_
#define LIBS_TRANSIT_INCLUDE_ROBOT_H_

#include <vector>
#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
/**
 * @brief This class inherits from the IEntity class
 * @brief The robot will be set to a specified position and wait
 * @brief to be picked up by a transport entity
 */
class Robot : public IEntity {
 public:
  /**
   * @brief Construct a new Robot object
   * 
   * @param obj Json that contains the details about the robot
   */
  Robot(const JsonObject& obj);
  /**
   * @brief Destroy the Robot object
   * 
   */
  ~Robot() override = default;
  /**
   * @brief Get the Position of the robot
   * 
   * @return Vector3 
   */
  Vector3 GetPosition() const { return position; }
  /**
   * @brief Get the Direction of the robot
   * 
   * @return Vector3 
   */
  Vector3 GetDirection() const { return direction; }
  /**
   * @brief Get the Destination of the robot
   * 
   * @return Vector3 
   */
  Vector3 GetDestination() const { return destination; }
  /**
   * @brief Get the Availability of the robot
   * 
   * @return true 
   * @return false 
   */
  bool GetAvailability() const { return available; }
  /**
   * @brief Get the Details of the robot
   * 
   * @return JsonObject 
   */
  JsonObject GetDetails() const override;
  /**
   * @brief Get the Pickup Vehicle of the robot
   * 
   * @return std::string 
   */
  std::string GetPickupVehicle() const { return pickupVehicle; }
  /**
   * @brief Get the Speed of the robot
   * 
   * @return float 
   */
  float GetSpeed() const { return speed; }
  /**
   * @brief Get the Strategy Name of the robot (from the scheduler)
   * 
   * @return std::string 
   */
  std::string GetStrategyName() {return strategyName;}
  /**
   * @brief Set the Availability of the robot
   * 
   * @param choice 
   */
  void SetAvailability(bool choice);
  /**
   * @brief Set the Position of the robot
   * 
   * @param pos_ 
   */
  void SetPosition(Vector3 pos_) { position = pos_; }
  /**
   * @brief Set the Direction of the robot
   * 
   * @param dir_ 
   */
  void SetDirection(Vector3 dir_) { direction = dir_; }
  /**
   * @brief Set the Destination of the robot
   * 
   * @param des_ 
   */
  void SetDestination(Vector3 des_) { destination = des_; }
  /**
   * @brief Set the Strategy Name of the robot
   * 
   * @param strategyName_ 
   */
  void SetStrategyName(std::string strategyName_)
  { strategyName = strategyName_;}
  /**
   * @brief Rotates the robot by angle
   * 
   * @param angle 
   */
  void Rotate(double angle);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
  std::string pickupVehicle;
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOT_H_

