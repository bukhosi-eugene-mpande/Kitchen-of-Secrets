#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>
#include <memory>

#include "GameComponent.h"

class GameComponent;

class Engine {
    protected:
        Engine();
        virtual void createGameComponents() = 0;
    public:
        virtual ~Engine();
        virtual void notify(std::shared_ptr<GameComponent> sender, std::string event) = 0;
        virtual void registerComponent(std::shared_ptr<GameComponent> component) = 0;
        virtual void unregisterComponent(std::shared_ptr<GameComponent> component) = 0;
};

#endif