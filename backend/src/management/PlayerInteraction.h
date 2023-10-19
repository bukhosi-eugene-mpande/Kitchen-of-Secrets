#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include <vector>
#include <queue>

#include "Command.h"
#include "Engine.h"

class PlayerInteraction : public GameComponent {
    private:
        /**
         * @brief 
         * 
         */
        std::vector<Command*> commands;

        /**
         * @brief 
         * 
         */
        std::vector<Command*> orderQueue;

        /**
         * @brief 
         * 
         */
        std::vector<Command*> customerQueue;
    public:
        /**
         * @brief Construct a new Player Interaction object
         * 
         * @param engine 
         */
        PlayerInteraction(Engine* engine) : GameComponent(engine) {}

        /**
         * @brief Destroy the Player Interaction object
         * 
         */
        ~PlayerInteraction() {}

        /**
         * @brief 
         * 
         * @param command 
         */
        void addCommand(Command* command) {commands.push_back(command);}

        /**
         * @brief 
         * 
         * @param index 
         */
        void removeCommand(std::vector<Command*>::iterator index) {commands.erase(index);}

        /**
         * @brief 
         * 
         */
        void paymentCommand();

        /**
         * @brief 
         * 
         */
        void updateInventoryCommand();

        /**
         * @brief 
         * 
         */
        void takeOrderCommand();

        /**
         * @brief 
         * 
         */
        void orderUpCommand();

        /**
         * @brief 
         * 
         */
        void seatCustomerCommand();

        /**
         * @brief 
         * 
         */
        virtual void sendNotification();

        /**
         * @brief 
         * 
         * @param message 
         */
        virtual void receiveNotification(std::string message);
};

#endif