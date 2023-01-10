#ifndef LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
#define LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

/**
 * @brief Controller Interface
 * @brief Abstract controller class used in the Transit service. Uses the Model view
 * @brief allows message to be passed back to and from the scheduler and simulation.
 * @brief Controller Pattern
 */
class IController {
 public:
  virtual ~IController() {}
  /**
   * @brief Adds an entity to the program
   */
  virtual void AddEntity(const IEntity& entity) = 0;
  /**
   * @brief Updates an entity in the program
   */
  virtual void UpdateEntity(const IEntity& entity) = 0;
  /**
   * @brief Removes an entity from the program
   */
  virtual void RemoveEntity(int id) = 0;
  /**
   * @brief Adds a path to the program
   */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
  /**
   * @brief Removes a path from the program
   */
  virtual void RemovePath(int id) = 0;
  /**
   * @brief Allows messages to be passed back to the view
   */
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

