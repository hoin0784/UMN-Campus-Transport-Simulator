#ifndef LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Robot.h"
#include <vector>
/**
 * @brief This class inherits from the IEntityFactory class and
 * @brief is responsible for generating robot.
 */
class RobotFactory : public IEntityFactory {
 public:
    /**
     * @brief Creates the robot object
     * 
     * @param entity json containing details about the robot
     * @return IEntity* robot object
     */
    IEntity* CreateEntity(const JsonObject& entity);
};

#endif  // LIBS_TRANSIT_INCLUDE_ROBOTFACTORY_H_
