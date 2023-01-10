#ifndef LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_CARFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Car.h"
#include <vector>
/**
 * @brief This class inherits from the IEntityFactory class and
 * @brief is responsible for generating a car.
 */
class CarFactory : public IEntityFactory {
 public:
    /**
     * @brief Destroy the Car Factory object
     * 
     */
    virtual ~CarFactory() {}
    /**
     * @brief Creates the car object
     * 
     * @param entity json containing details about the car
     * @return IEntity* car object
     */
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  //  LIBS_TRANSIT_INCLUDE_CARFACTORY_H_
