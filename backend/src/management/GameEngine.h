#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Engine.h"

class GameEngine : public Engine {
    private:
<<<<<<< HEAD
        /**
         * @brief  `std::vector<GameComponent*> gameComponents;` is declaring a private 
         * member variable `gameComponents` of type `std::vector<GameComponent*>`.
         */
        std::vector<GameComponent*> gameComponents;
    public:
        /**
         * @brief The `GameEngine` constructor is taking a parameter `gameComponents` of type 
         * `std::vector<GameComponent*>`. This parameter is used to initialize the private 
         * member variable `gameComponents` of the `GameEngine` class.
         * 
         * @param gameComponents 
         */
        GameEngine(std::vector<GameComponent*> gameComponents);

        /**
         * @brief Destroy the Game Engine object
         * 
         */
        ~GameEngine();

        /**
         * @brief The `virtual void notify(GameComponent* sender, std::string message);` 
         * function is declaring a virtual member function named `notify` that takes two parameters: 
         * `sender` of type `GameComponent*` and `message` of type `std::string`.
         * 
         * @param sender 
         * @param message 
         */
        virtual void notify(GameComponent* sender, std::string message);

        /**
         * @brief The `void reactOnGameComponent(int index)` function is a member function of the 
         * `GameEngine` class. It takes an integer parameter `index`. This function is responsible for 
         * reacting to a game component at the specified index. The specific implementation of this 
         * function is not provided in the code snippet, so it is unclear what actions it performs.
         * 
         * @param index 
         */
        void reactOnGameComponent(int index);
=======
        std::vector<GameComponent*> gameComponent;
    public:
        GameEngine(std::vector<GameComponent*> GameComponent);
        ~GameEngine();
        virtual void notify(GameComponent* sender, std::string message);
>>>>>>> accounting
};

#endif