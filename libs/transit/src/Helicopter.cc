#include "Helicopter.h"
#include "HeliBeeline.h"

void Helicopter::SetStrategies() {
    toTargetPosStrategy = new HeliBeeline(this->GetPosition(), destination);

    toTargetDestStrategy = new HeliBeeline(
        nearestEntity->GetPosition(), nearestEntity->GetDestination());
}
