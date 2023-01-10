#ifndef LIBS_TRANSIT_INCLUDE_CAR_H_
#define LIBS_TRANSIT_INCLUDE_CAR_H_

#include "ITransEntity.h"
/**
 * @brief Car class is a transport vehicle that inherits
 * @brief from ITransEntity
 */
class Car : public ITransEntity {
 public:
       /**
        * @brief Construct a new Car object
        * 
        * @param obj Json that contains details about the car
        */
       Car(const JsonObject& obj) : ITransEntity(obj) {}
 protected:
       /**
        * @brief Helper function to set the strategies of the car
        * 
        */
       void SetStrategies();
};  //  end class
#endif  // LIBS_TRANSIT_INCLUDE_CAR_H_
