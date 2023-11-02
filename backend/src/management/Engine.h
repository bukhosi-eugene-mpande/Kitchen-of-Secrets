#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>
#include <memory>

#include "GameComponent.h"

class GameComponent;

/**
 * @brief 
 * 
 */
class Engine {
    protected:
        Engine();
        virtual void createGameComponents() = 0;
    public:
        virtual ~Engine();
        virtual void notify(std::shared_ptr<GameComponent> sender, std::string message) = 0;
};

#endif