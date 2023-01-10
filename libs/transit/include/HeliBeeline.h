#ifndef LIBS_TRANSIT_INCLUDE_HELIBEELINE_H_
#define LIBS_TRANSIT_INCLUDE_HELIBEELINE_H_

#include "IStrategy.h"
#include "BeelineStrategy.h"
#include "VertBeeline.h"

/**
 * @brief Pathing strategy that inherits from IStrategy.
 * @brief Makes the helicopter move regularly instead of a standard beeline
 */

class HeliBeeline : public IStrategy {
 public:
    /**
     * @brief Construct a new Heli Beeline object
     * 
     * @param position sets the starting position
     * @param destination sets the destination
     */
    HeliBeeline(Vector3 position, Vector3 destination);
    /**
     * @brief Destroy the Heli Beeline object
     * 
     */
    ~HeliBeeline();
    /**
    * @brief Moves the robot and the transport entity towards destination
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
    IStrategy* upBeeline;
    IStrategy* horizontalBeeline;
    IStrategy* downBeeline;
    bool allDone;
};

#endif  // LIBS_TRANSIT_INCLUDE_HELIBEELINE_H_
