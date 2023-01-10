#ifndef LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
#define LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_

#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief This class inhertis from the IStrategy class and 
 * @brief is responsible for generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
 public:
   /**
    * @brief Construct a new Beeline Strategy object
    * 
    * @param position sets the starting position
    * @param destination sets the destination
    */
    BeelineStrategy(Vector3 position, Vector3 destination);
   /**
     * @brief Destroy the Beeline Strategy object
     * 
     */
    ~BeelineStrategy();
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
    Vector3 position;
    Vector3 destination;
};  //  end class
#endif  //  LIBS_TRANSIT_INCLUDE_BEELINESTRATEGY_H_
