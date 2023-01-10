#include "VertBeeline.h"

VertBeeline::VertBeeline(Vector3 position, Vector3 destination) {
    this->position = position;
    this->destination = destination;
}

bool VertBeeline::IsCompleted() {
    return (destination - position).Magnitude() <1.0;
}

void VertBeeline::Move(IEntity* entity, double dt) {
    position = entity->GetPosition();
    Vector3 dir = (destination - position).Unit();

    float speed = entity->GetSpeed();
    position = position + dir * speed * dt;

    entity->SetPosition(position);
    // entity->SetDirection(dir);
}
