// #include "GameEngine.h"
// #include <algorithm>

// GameEngine::GameEngine() : Engine() {}

// GameEngine::~GameEngine() {}

// void GameEngine::notify(std::shared_ptr<GameComponent> sender, std::string event) {
//     for (std::shared_ptr<GameComponent> component : gameComponents) {
//         if (component != sender) {
//             component->receiveEvent(event);
//         }
//     }
// }

// void GameEngine::registerGameComponent(std::shared_ptr<GameComponent> gameComponent){
//     gameComponents.push_back(gameComponent);
// }

// void GameEngine::unregisterGameComponent(std::shared_ptr<GameComponent> gameComponent)
// {
//     auto it = std::find(gameComponents.begin(), gameComponents.end(), gameComponent);
//     if (it != gameComponents.end()) {
//         gameComponents.erase(it);
//     }
// }