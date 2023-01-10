#include "Drone.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "AstarStrategy.h"
#include "DijkstraStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"

void Drone::SetStrategies() {
    toTargetPosStrategy = new BeelineStrategy(this->GetPosition(), destination);

    if (strategyName.compare("astar") == 0) {
        toTargetDestStrategy =
        new AstarStrategy(nearestEntity->GetPosition(),
        nearestEntity->GetDestination(), graph);

        toTargetDestStrategy =
        new SpinDecorator(toTargetDestStrategy);

    } else if (strategyName.compare("dfs") == 0) {
        toTargetDestStrategy =
        new DfsStrategy(nearestEntity->GetPosition(),
        nearestEntity->GetDestination(), graph);

        toTargetDestStrategy =
        new JumpDecorator(toTargetDestStrategy);

    } else if (strategyName.compare("dijkstra") == 0) {
        toTargetDestStrategy =
        new DijkstraStrategy(nearestEntity->GetPosition(),
        nearestEntity->GetDestination(), graph);

        toTargetDestStrategy =
        new SpinDecorator(toTargetDestStrategy);

        toTargetDestStrategy =
        new JumpDecorator(toTargetDestStrategy);

    } else {
        std::cout << "Error in Drone.cc" << std::endl;
    }
}
