#ifndef BANK_H
#define BANK_H

#include "GameComponent.h"

/**
 * @brief Class that holds the player's finances
 * 
 */
class Bank : public GameComponent {
    private:
        /**
         * @brief The player's finances
         * 
         */
        double amount;
    public:
        /**
         * @brief Construct a new Bank object
         * 
         * @param engine 
         */
        Bank(Engine* engine) : GameComponent(engine) {amount = 0.0;}

        /**
         * @brief Destroy the Bank object
         * 
         */
        ~Bank() {}

        /**
         * @brief Get the Amount object
         * 
         * @return double 
         */
        double getAmount() {return amount;}

        /**
         * @brief Set the Amount object
         * 
         * @param amount 
         */
        void setAmount(double amount) {this->amount = amount;}

        /**
         * @brief 
         * 
         * @param cost 
         */
        void buyInventory(double cost);

        /**
         * @brief 
         * 
         */
        virtual void sendInventory();

        /**
         * @brief 
         * 
         * @param message 
         */
        virtual void receiveInventory(std::string message);
};

#endif