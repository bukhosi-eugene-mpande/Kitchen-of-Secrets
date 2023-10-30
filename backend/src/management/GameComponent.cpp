#include "GameComponent.h"

GameComponent::GameComponent(Engine* engine) {
    this->engine = engine;
}

void GameComponent::changed(std::string message) {
    engine->notify(this, message);
}
