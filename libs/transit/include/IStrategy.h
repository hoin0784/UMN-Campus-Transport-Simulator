#ifndef LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;

/**
 * @brief This is a strategy abstraction that is used in all the strategies in
 * @brief the system. This includes pathing algorithms and celebration decorators
 */
class IStrategy {
 public:
    /**
    * @brief Moves the robot and transport vehicle towards destination or celebrates
    * 
    * @param entity Robot to be moved
    * @param dt time passed since last move
    */
    virtual void Move(IEntity* entity, double dt) = 0;
    /**
     * @brief Checks if strategy is done
     * 
     * @return true 
     * @return false 
     */
    virtual bool IsCompleted() = 0;
 protected:
    const IGraph* graph;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_ISTRATEGY_H_
