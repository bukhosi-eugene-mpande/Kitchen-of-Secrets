#ifndef Game_Runner_H
#define Game_Runner_H

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

#include "../customercare/CustomerTemplate.h"
#include "../customercare/Customer.h"
#include "../customercare/CustomerNPC.h"
#include "../ordering/Waiter.h"
#include "../cooking/Kitchen.h"
#include "../cooking/HeadChef.h"
#include "../accounting/Tab.h"
#include "PlayerInteraction.h"

/**
 * @brief The GameRunner class is responsible for managing the game and its interactions.
 */
class GameRunner{

    private:
        std::shared_ptr<PlayerInteraction> playerInteraction;

        std::shared_ptr<Kitchen> kitchen;

        std::shared_ptr<Customer> customer;

        std::shared_ptr<CustomerNPC> customer2;

        std::shared_ptr<Waiter> waiter;

        std::shared_ptr<Tab> tab;

        bool foodFlag;

        bool beverageFlag;

    public:
        /**
         * @brief Constructs a new GameRunner object.
         */
        GameRunner();

        /**
         * @brief Starts the game.
         * 
         * @param section The section of the restaurant to start the game in.
         */
        void startGame(std::string section);

        /**
         * @brief Requests a reservation for the game.
         * 
         * @param section The section of the restaurant to reserve.
         */
        void requestReservation(std::string section);

        /**
         * @brief Sends a beverage order to the kitchen.
         * 
         * @param order The order to send.
         */
        void sendBeverageOrder(std::unordered_map<std::string,int> order);

        /**
         * @brief Sends a food order to the kitchen.
         * 
         * @param order The order to send.
         */
        void sendFoodOrder(std::unordered_map<std::string,int> order);

        /**
         * @brief Changes the mood of the customers.
         */
        void changeMood();

        /**
         * @brief Processes a payment for the game.
         * 
         * @param payment The payment method to use.
         * @param bill The total bill to pay.
         * @return std::string The payment confirmation message.
         */
        std::string payment(std::string payment,double bill);

        /**
         * @brief Performs the rounds for the chef.
         */
        void doRoundsChef();

        /**
         * @brief Performs the rounds for the waiter.
         */
        void doRoundsWaiter();

        /**
         * @brief Gets the food menu for the restaurant.
         * 
         * @return std::unordered_map<int,std::string> The food menu.
         */
        std::unordered_map<int,std::string> getFoodMenu();

        /**
         * @brief Gets the beverage menu for the restaurant.
         * 
         * @return std::unordered_map<int,std::string> The beverage menu.
         */
        std::unordered_map<int,std::string> getBeverageMenu();

        /**
         * @brief adds the bill to tab 
         * 
         * @param bill The total bill added to the tab.
         * @return std::string The payment confirmation message.
         */
        std::string addToTab(double bill);

        /**
         * @brief get the tab 
         */

        std::shared_ptr<Tab> getTab();


};


#endif