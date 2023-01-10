#ifndef LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Drone.h"
#include <vector>
/**
 * @brief This class inherits from the IEntityFactory class and
 * @brief is responsible for generating drone.
 */
class DroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Destroy the Drone Factory object
   * 
   */
  virtual ~DroneFactory() {}
  /**
   * @brief Create a drone object
   * 
   * @param entity json containing details about the drone
   * @return IEntity* car object
   */
  IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_DRONEFACTORY_H_
