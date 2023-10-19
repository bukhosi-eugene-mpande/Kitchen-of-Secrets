#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Engine.h"

class GameEngine : public Engine {
    private:
        /**
         * @brief 
         * 
         */
        std::vector<GameComponent*> gameComponents;
    public:
        /**
         * @brief Construct a new Game Engine object
         * 
         * @param gameComponents 
         */
        GameEngine(std::vector<GameComponent*> gameComponents) {this->gameComponents = gameComponents;}

        /**
         * @brief Destroy the Game Engine object
         * 
         */
        ~GameEngine() {}

        /**
         * @brief 
         * 
         * @param sender 
         * @param message 
         */
        virtual void notify(GameComponent* sender, std::string message);

        /**
         * @brief 
         * 
         * @param index 
         */
        void reactOnGameComponent(int index);
};

#endif