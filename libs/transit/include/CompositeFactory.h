#ifndef LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
#define LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_

#include "IEntityFactory.h"
/**
 * @brief This class inherits from the IEntityFactory
 * @brief This Composite pattern allows us to treat a group of object as a single.
 *
 **/
class CompositeFactory : public IEntityFactory {
 public:
    /**
     * @brief Create a Entity object
     * 
     * @param entity json containing details about the entity
     * @return IEntity* entity object
     */
    IEntity* CreateEntity(const JsonObject& entity);
    /**
     * @brief Adds a factory to the factory vector
     * 
     * @param factoryEntity Factory to be added
     */
    void AddFactory(IEntityFactory* factoryEntity);
    /**
     * @brief Destroy the Composite Factory object
     * 
     */
    virtual ~CompositeFactory();

 private:
    std::vector<IEntityFactory*> componentFactories;
};

#endif  //  LIBS_TRANSIT_INCLUDE_COMPOSITEFACTORY_H_
