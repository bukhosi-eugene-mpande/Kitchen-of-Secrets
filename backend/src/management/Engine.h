#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>

#include "GameComponent.h"

class GameComponent;

class Engine
{
    public:
        virtual ~Engine() {}
        virtual void notify(GameComponent* sender, std::string message) = 0;
    protected:
        Engine() {}
};

#endif