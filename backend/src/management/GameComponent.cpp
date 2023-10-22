#include "GameComponent.h"

GameComponent::GameComponent(std::unique_ptr<Engine> engine) {
    this->engine = std::move(engine);
}

void GameComponent::changed(std::string message) {
    engine->notify(this, message);
}
