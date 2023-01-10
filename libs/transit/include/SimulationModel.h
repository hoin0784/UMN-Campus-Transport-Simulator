#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;
/**
 * @brief Simulation Model class handling the transit simulation. The model can communicate
 * @brief with the controller.
 */
class SimulationModel {
 public:
  /**
   * @brief Construct a new Simulation Model object
   * 
   * @param controller 
   */
  SimulationModel(IController& controller);
  /**
   * @brief Set the Graph object
   * 
   * @param graph 
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
/**
 * @brief Creates an simulation entity
 */
  void CreateEntity(const JsonObject& entity);
/**
 * @brief Schedules a trip for an object in the scene
 */
  void ScheduleTrip(const JsonObject& details);
/**
 * @brief Updates the simulation (called very frequently)
 */
  void Update(double dt);
  /**
   * @brief Adds a new entity type to the entity factory vector
   */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
