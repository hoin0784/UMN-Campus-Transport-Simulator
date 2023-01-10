#ifndef LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_

#include "util/json.h"
#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"

/**
 * @brief This class is the parent class of Helicopter Factory, Car Factory, Robot Factory, and Drone Factory
 * @brief Abstraction for a entity factory that is used in creating objects
 */
class IEntityFactory {
 public:
    /**
     * @brief Destroy the IEntityFactory object
     * 
     */
    virtual ~IEntityFactory() {}
    /**
     * @brief Create a Entity object
     * 
     * @param entity json containing details about the entity
     * @return IEntity* entity object
     */
    virtual IEntity* CreateEntity(const JsonObject& entity) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_IENTITYFACTORY_H_
