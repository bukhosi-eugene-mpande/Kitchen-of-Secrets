#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include <string>
#include <iostream>
#include <memory>

#include "Engine.h"

class Engine;

class GameComponent : public std::enable_shared_from_this<GameComponent> {
    protected:
        std::shared_ptr<Engine> engine;
    public:
        GameComponent(std::shared_ptr<Engine> engine);
        virtual void changed();
};

#endif