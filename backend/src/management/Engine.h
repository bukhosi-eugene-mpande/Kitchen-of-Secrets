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
         * @brief The `Engine();` is a constructor declaration for the `Engine`
         * class. It is used to create and initialize an instance of the `Engine` class.
         */
        Engine();

        /**
         * @brief `virtual ~Engine();` is declaring a virtual destructor for the `Engine` class. A 
         * destructor is a special member function that is called when an object of a class is destroyed. 
         * The `virtual` keyword indicates that the destructor can be overridden by derived classes.
         */
        virtual ~Engine();

        /**
         * @brief The line `virtual void notify(GameComponent* sender, std::string message) = 0;` is 
         * declaring a pure virtual function called `notify` in the `Engine` class. The `notify` function
         * is called everytime one of the concrete game components executes the `changed` function; telling
         * the engine which game component made the change. It is designed to keep the interface generic 
         * by not sharing the specifics of the change. The mediator's job is to collect information about 
         * what changed and share that with all colleagues.
         * 
         * @param sender 
         * @param message 
         */
        virtual void notify(std::unique_ptr<GameComponent> sender, std::string message) = 0;
};

#endif