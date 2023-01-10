#ifndef LIBS_TRANSIT_INCLUDE_DRONE_H_
#define LIBS_TRANSIT_INCLUDE_DRONE_H_

#include "ITransEntity.h"
/**
 * @brief Robot class that represents the entity to be moved
 **/
class Drone : public ITransEntity {
 public:
    /**
     * @brief Construct a new Drone object
     * 
     * @param obj Json that contains details about the robot
     */
    Drone(const JsonObject& obj) : ITransEntity(obj) {}
 protected:
    /**
    * @brief Helper function to set the strategies of the car
    * 
    */
    void SetStrategies();
};  // end class
#endif  //  LIBS_TRANSIT_INCLUDE_DRONE_H_
