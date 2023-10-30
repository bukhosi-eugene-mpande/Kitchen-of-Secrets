#include "GameEngine.h"

GameEngine::GameEngine(std::vector<GameComponent*> gameComponents) {
    this->gameComponents = gameComponents;
}

GameEngine::~GameEngine() {}

void GameEngine::notify(GameComponent* sender, std::string message) {
    
}

void GameEngine::reactOnGameComponent(int index) {
}
