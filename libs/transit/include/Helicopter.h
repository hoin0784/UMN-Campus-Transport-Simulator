#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

#include "ITransEntity.h"

/**
 * @brief Helicopter class is a transport vehicle that inherits
 * @brief from ITransEntity
 */
class Helicopter : public ITransEntity {
 public:
   /**
    * @brief Construct a new Helicopter object
    * 
    * @param obj Json that contains details about the helicopter
    */
    Helicopter(const JsonObject& obj) : ITransEntity(obj) {}
 protected:
    /**
     * @brief Helper function to set the strategies of the car
     * 
     */
    void SetStrategies();
};

#endif  //  LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

