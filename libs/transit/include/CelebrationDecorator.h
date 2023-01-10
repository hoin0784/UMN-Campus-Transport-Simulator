#ifndef LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
#define LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_

#include <vector>
#include "IStrategy.h"
/**
 * @brief This class inherits from IStrategy, and is a decorator for celebrations
 */
class CelebrationDecorator : public IStrategy {
 public:
  /**
   * @brief Construct a new Celebration Decorator object
   * 
   * @param strategy_ 
   */
  CelebrationDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
  }
  /**
   * @brief check if current strategy and previous strategy has completed.
   * @brief If the previous strategy has completed, then do current strategy movement ex) spin/Jump.
   * 
   * @param entity Entity to move
   * @param dt time passed since last move
   */
  void Move(IEntity *entity, double dt);
  /**
   * @brief Checks if Celebration is done
   * 
   * @return true
   * @return false
   */
  bool IsCompleted();

 protected:
  IStrategy *strategy;
  float time;
};  // close class

#endif  // LIBS_TRANSIT_INCLUDE_CELEBRATIONDECORATOR_H_
