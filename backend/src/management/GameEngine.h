#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Engine.h"

class GameEngine : public Engine {
    private:
        std::vector<GameComponent*> gameComponent;
    public:
        GameEngine(std::vector<GameComponent*> GameComponent);
        ~GameEngine();
        virtual void notify(GameComponent* sender, std::string message);
};

#endif