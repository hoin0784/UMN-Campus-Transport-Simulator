#ifndef LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Helicopter.h"
#include <vector>

/**
 * @brief This class inherits from the IEntityFactory class and
 * @brief is responsible for generating Helicopter.
 */
class HelicopterFactory : public IEntityFactory {
 public:
  /**
   * @brief Destroy the Helicopter Factory object
   * 
   */
  virtual ~HelicopterFactory() {}
  /**
   * @brief Creates the helicopter object
   * 
   * @param entity json containing details about the helicopter
   * @return IEntity* helicopter object
   */
  IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_HELICOPTERFACTORY_H_
