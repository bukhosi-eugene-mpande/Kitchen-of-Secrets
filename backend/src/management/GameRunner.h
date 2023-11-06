/**
 * @file GameRunner.h
 * @brief Contains the declaration of the GameRunner class.
 */

#ifndef GAME_RUNNER_H
#define GAME_RUNNER_H

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
#include "PlayerInteraction.h"

/**
 * @class GameRunner
 * @brief Manages the gameplay and interactions of the restaurant simulation game.
 *
 * The GameRunner class is responsible for managing the gameplay and interactions in a restaurant simulation game. It handles the interactions between customers, waiters, chefs, and the kitchen, and provides methods for managing reservations, orders, payments, and more.
 */
class GameRunner {
private:
    std::shared_ptr<PlayerInteraction> playerInteraction; ///< A pointer to the player interaction manager.
    std::shared_ptr<Kitchen> kitchen; ///< A pointer to the kitchen where food is prepared.
    std::shared_ptr<Customer> customer; ///< A pointer to a customer.
    std::shared_ptr<CustomerNPC> customer2; ///< A pointer to another customer (NPC).
    std::shared_ptr<Waiter> waiter; ///< A pointer to the waiter serving the customers.
    bool foodFlag; ///< A flag to indicate the availability of food.
    bool beverageFlag; ///< A flag to indicate the availability of beverages.

public:
    /**
     * @brief Constructor for the GameRunner class.
     */
    GameRunner();

    /**
     * @brief Start the restaurant simulation game for a specific section.
     * @param section The section of the restaurant where the game should be played.
     */
    void startGame(std::string section);

    /**
     * @brief Request a reservation for a specific section.
     * @param section The section of the restaurant where the reservation is requested.
     */
    void requestReservation(std::string section);

    /**
     * @brief Send a beverage order to the kitchen.
     * @param order An unordered map representing the beverage order.
     */
    void sendBeverageOrder(std::unordered_map<std::string, int> order);

    /**
     * @brief Send a food order to the kitchen.
     * @param order An unordered map representing the food order.
     */
    void sendFoodOrder(std::unordered_map<std::string, int> order);

    /**
     * @brief Change the mood or satisfaction level of customers.
     */
    void changeMood();

    /**
     * @brief Process a payment for an order.
     * @param payment The type of payment (e.g., cash, card).
     * @param bill The total amount to be paid.
     * @return A message indicating the result of the payment.
     */
    std::string payment(std::string payment, double bill);

    /**
     * @brief Perform kitchen rounds for chefs.
     */
    void doRoundsChef();

    /**
     * @brief Perform rounds for waiters.
     */
    void doRoundsWaiter();

    /**
     * @brief Get the food menu as an unordered map.
     * @return An unordered map representing the food menu.
     */
    std::unordered_map<int, std::string> getFoodMenu();

    /**
     * @brief Get the beverage menu as an unordered map.
     * @return An unordered map representing the beverage menu.
     */
    std::unordered_map<int, std::string> getBeverageMenu();
};

#endif
