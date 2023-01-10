#ifndef LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_

#include <vector>
#include "CelebrationDecorator.h"
#include "IStrategy.h"

/**
 * @brief This class inherits from the CelebrationDecorator class
 * @brief When the previous strategy has completed, then
 * @brief do current strategy movement (jump)
 */
class JumpDecorator : public CelebrationDecorator {
 public:
  /**
   * @brief Construct a new Jump Decorator object
   * 
   * @param strategy_ strategy that this decorator waits to finish until performing its action
   */
  JumpDecorator(IStrategy* strategy_) : CelebrationDecorator(strategy_) {}
  /**
   * @brief Checks if Celebration is done
   * 
   * @return true
   * @return false
   */
  bool IsCompleted();
  /**
   * @brief check if current strategy and previous strategy has completed.
   * @brief If the previous strategy has completed, jump.
   * 
   * @param entity Entity to move
   * @param dt time passed since last move
   */
  void Move(IEntity* entity, double dt);
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_JUMPDECORATOR_H_
