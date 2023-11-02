#include "GameComponent.h"

GameComponent::GameComponent(std::shared_ptr<Engine> engine) {
    this->engine = engine;
}

void GameComponent::changed() {
    engine->notify(shared_from_this());
}
