#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include <string>
#include <iostream>
#include "Engine.h"

class Engine;

class GameComponent 
{
    protected:
        Engine* engine;
    public:
        GameComponent(Engine* engine) {this->engine = engine;}
        virtual void changed(std::string message) {engine->notify(this, message);}
        virtual void sendNotification() = 0;
        virtual void receiveNotification(std::string message) = 0;
};

#endif