#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include <string>
#include <iostream>
#include "Engine.h"

class Engine;

class GameComponent 
{
    protected:
        /**
         * @brief 
         * 
         */
        Engine* engine;
    public:

        /**
         * @brief Construct a new Game Component object
         * 
         * @param engine 
         */
        GameComponent(Engine* engine) {this->engine = engine;}

        /**
         * @brief 
         * 
         * @param message 
         */
        virtual void changed(std::string message) {engine->notify(this, message);}

        /**
         * @brief 
         * 
         */
        virtual void sendNotification() = 0;

        /**
         * @brief 
         * 
         * @param message 
         */
        virtual void receiveNotification(std::string message) = 0;
};

#endif