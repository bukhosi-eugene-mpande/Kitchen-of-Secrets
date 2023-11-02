#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

<<<<<<< HEAD
#include "Engine.h"

#include <string>
#include <iostream>
#include <memory>
=======
#include <string>
#include <iostream>
#include "Engine.h"
>>>>>>> accounting

class Engine;

class GameComponent 
{
    protected:
<<<<<<< HEAD
        /**
         * @brief `Engine* engine` is declaring a member variable named `engine` of type 
         * `Engine*`.
         */
        Engine* engine;
    public:

        /**
         * @brief The line `GameComponent(Engine* engine);` is declaring a constructor for 
         * the `GameComponent` class that takes a single parameter of type `Engine*`. This 
         * constructor is used to create a new `GameComponent` object and initialize its `engine` member 
         * variable with the provided `Engine*`.
         * 
         * @param engine 
         */
        GameComponent(Engine* engine);

        /**
         * @brief The line `virtual void changed(std::string message);` is declaring a virtual member 
         * function named `changed` that takes a single parameter of type `std::string`. This function 
         * does not have an implementation in the `GameComponent` class, but it can be overridden by 
         * derived classes. The purpose of this function is to handle any changes or updates in the game 
         * component and take appropriate actions based on the provided message.
         * 
         * @param message 
         */
        virtual void changed(std::string message);

        /**
         * @brief The line `virtual void sendNotification() = 0` is declaring a pure virtual function 
         * named `sendNotification()`.
         */
        virtual void sendNotification() = 0;

        /**
         * @brief The line `virtual void receiveNotification(std::string message) = 0` is declaring a pure 
         * virtual function named `receiveNotification`.
         * 
         * @param message 
         */
=======
        Engine* engine;
    public:
        GameComponent(Engine* engine) {this->engine = engine;}
        virtual void changed(std::string message) {engine->notify(this, message);}
        virtual void sendNotification() = 0;
>>>>>>> accounting
        virtual void receiveNotification(std::string message) = 0;
};

#endif