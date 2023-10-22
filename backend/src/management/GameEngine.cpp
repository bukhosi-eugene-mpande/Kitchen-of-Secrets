#include "GameEngine.h"

GameEngine::GameEngine(std::vector<std::unique_ptr<GameComponent>> gameComponents) {
    this->gameComponents = gameComponents;
}

GameEngine::~GameEngine() {}

void GameEngine::notify(std::unique_ptr<GameComponent> sender, std::string message) {
}

void GameEngine::reactOnGameComponent(int index) {
}
