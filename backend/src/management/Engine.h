#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>

#include "GameComponent.h"

class GameComponent;

/**
 * @brief 
 * 
 */
class Engine
{
    public:
        /**
         * @brief Construct a new Engine object
         * 
         */
        Engine() {}

        /**
         * @brief Destroy the Engine object
         * 
         */
        virtual ~Engine() {}

        /**
         * @brief 
         * 
         * @param sender 
         * @param message 
         */
        virtual void notify(GameComponent* sender, std::string message) = 0;
};

#endif