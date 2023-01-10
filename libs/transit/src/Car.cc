#include "Car.h"
#include "DfsStrategy.h"
#include "AstarStrategy.h"
#include "DijkstraStrategy.h"
#include "SpinDecorator.h"
#include "JumpDecorator.h"

void Car::SetStrategies() {
    if (strategyName.compare("astar") == 0) {
        toTargetPosStrategy =
        new AstarStrategy(this->GetPosition(), destination, graph);

        toTargetDestStrategy =
        new AstarStrategy(nearestEntity->GetPosition(),
        nearestEntity->GetDestination(), graph);

        toTargetDestStrategy =
        new SpinDecorator(toTargetDestStrategy);

    } else if (strategyName.compare("dfs") == 0) {
        toTargetPosStrategy =
        new DfsStrategy(this->GetPosition(), destination, graph);

        toTargetDestStrategy =
        new DfsStrategy(nearestEntity->GetPosition(),
        nearestEntity->GetDestination(), graph);

        toTargetDestStrategy =
        new JumpDecorator(toTargetDestStrategy);

    } else if (strategyName.compare("dijkstra") == 0) {
        toTargetPosStrategy =
        new DijkstraStrategy(this->GetPosition(), destination, graph);

        toTargetDestStrategy =
        new DijkstraStrategy(
            nearestEntity->GetPosition(),
            nearestEntity->GetDestination(), graph);

        toTargetDestStrategy =
        new SpinDecorator(toTargetDestStrategy);

        toTargetDestStrategy =
        new JumpDecorator(toTargetDestStrategy);

    } else {
        std::cout << "Error in car.cc" << std::endl;
    }
}
