#ifndef LIBS_TRANSIT_INCLUDE_VERTBEELINE_H_
#define LIBS_TRANSIT_INCLUDE_VERTBEELINE_H_

#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief This class inherits from the IStrategy class 
 * @brief and is responsible for generating the vertical portion of the helicopters movement.
 */
class VertBeeline : public IStrategy {
 public:
    /**
     * @brief Construct a new Vert Beeline object
     * 
     * @param position sets the starting position
     * @param destination sets the destination
     */
    VertBeeline(Vector3 position, Vector3 destination);
    /**
     * @brief Destroy the Vert Beeline object
     * 
     */
    ~VertBeeline();
    /**
    * @brief Moves the robot (if picked up) and the helicopter towards destination
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
};  // end class
#endif  // LIBS_TRANSIT_INCLUDE_VERTBEELINE_H_
