#ifndef LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief Pathing strategy that inherits from IStrategy
 * 
 */
class AstarStrategy : public IStrategy {
 public:
    /**
    * @brief Construct a new Astar Strategy object
    * 
    * @param position sets the starting position
    * @param destination sets the destination
    * @param graph used to create path
    */
    AstarStrategy(Vector3 position, Vector3 destination, const IGraph* graph);
    /**
    * @brief Destroy the Astar Strategy object
    * 
    */
    ~AstarStrategy();
    /**
    * @brief Moves the robot (if picked up) and the transport entity towards destination
    * 
    * @param entity Robot to be moved
    * @param dt time passed since last move
    */
    void Move(IEntity* entity, double dt);
    /**
    * @brief Checks if strategy is done pathing
    * 
    * @return true if done pathing to destination
    * @return false if not done
    */
    bool IsCompleted();

 private:
    std::vector<std::vector<float>> path;
    int currentIndex;
    int maxIndex;
};  // end class
#endif  // LIBS_TRANSIT_INCLUDE_ASTARSTRATEGY_H_
