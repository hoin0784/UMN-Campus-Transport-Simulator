#include "HeliBeeline.h"
using namespace std;

HeliBeeline::HeliBeeline(Vector3 position, Vector3 destination) {
    Vector3 up_position = Vector3(position.x, 400, position.z);
    Vector3 up_destination = Vector3(destination.x, 400, destination.z);

    upBeeline = new VertBeeline(position, up_position);
    horizontalBeeline = new BeelineStrategy(up_position, up_destination);
    downBeeline = new VertBeeline(up_destination, destination);

    allDone = false;
}

HeliBeeline::~HeliBeeline() {
    delete upBeeline;
    delete horizontalBeeline;
    delete downBeeline;
}

bool HeliBeeline::IsCompleted() {
    return allDone;
}

void HeliBeeline::Move(IEntity* entity, double dt) {
    if (!upBeeline->IsCompleted()) {
        upBeeline->Move(entity, dt);
    } else if (!horizontalBeeline->IsCompleted()) {
        horizontalBeeline->Move(entity, dt);
    } else if (!downBeeline->IsCompleted()) {
        downBeeline->Move(entity, dt);
    } else {
        allDone = true;
    }
}
