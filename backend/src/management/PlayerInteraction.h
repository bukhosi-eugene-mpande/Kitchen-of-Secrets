
/**
 * @file PlayerInteraction.h
 * @brief Contains the declaration of the PlayerInteraction class.
 */

#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "../json.hpp"

using json = nlohmann::json;

class Waiter;
class Kitchen;
class Inventory;
class ReservationSystem;
class Receptionist;
class Section;
class CustomerTemplate;
class Table;
class Accounting;
class MenuItem;
class Order;
class Cuisine;
class Drink;

/**
 * @class PlayerInteraction
 * @brief Manages interactions and communication between different parts of the restaurant simulation game.
 *
 * The PlayerInteraction class is responsible for managing interactions and communication between various components of the restaurant simulation game. It facilitates interactions between customers, waiters, kitchen staff, inventory management, reservations, and more.
 */
class PlayerInteraction {
private:
    std::shared_ptr<ReservationSystem> reservationSystem; ///< A pointer to the reservation system.
    std::shared_ptr<Receptionist> receptionist; ///< A pointer to the receptionist.
    std::shared_ptr<CustomerTemplate> customer; ///< A pointer to a customer.
    std::shared_ptr<Inventory> inventory; ///< A pointer to the inventory management system.
    std::shared_ptr<Kitchen> kitchen; ///< A pointer to the kitchen where food is prepared.
    std::shared_ptr<Accounting> accounting; ///< A pointer to the accounting system.

public:
    /**
     * @brief Constructor for the PlayerInteraction class.
     */
    PlayerInteraction();

    /**
     * @brief Destructor for the PlayerInteraction class.
     */
    ~PlayerInteraction();

    // Interaction between customer and reservation

    /**
     * @brief Clear and clean a table after the customer has left.
     * @param table A pointer to the table to be cleared.
     */
    void clearOutTable(std::shared_ptr<Table> table);

    /**
     * @brief Notify the player of changes in customer mood.
     */
    void notifyPlayerOfChangeInMood();

    /**
     * @brief Request a reservation for a customer in a specific section.
     * @param customer A pointer to the customer.
     * @param section The section of the restaurant where the reservation is requested.
     */
    void requestReservation(std::shared_ptr<CustomerTemplate> customer, std::string section);

        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);

        // interactions between the customer and the waiter

        void notifyWaiterOfCancellation(Waiter* waiter);

        void notifyWaiterOfCompletion(Waiter* waiter);

        std::shared_ptr<Section> getGeneralSection();

        std::shared_ptr<Section> getPrivateSection();

        bool requestIngredients(std::unordered_map<std::string,int> ingredients);
        
        void sendOrderToKitchen(std::shared_ptr<Order> order);  

        std::shared_ptr<Order> getOrderFromKitchen();

        std::shared_ptr<Order> getCanceledOrderFromKitchen();

        std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();

        std::string pay(std::string payment,double bill);

        std::unordered_map<int,std::string> getCuisineMenu();

        std::unordered_map<int,std::string> getDrinksMenu();

        std::shared_ptr<Cuisine> getCusine(std::string name);

        std::shared_ptr<Drink> getDrink(std::string name);

        void setInventory(std::shared_ptr<Inventory> inventory);

        void setKitchen(std::shared_ptr<Kitchen> kitchen);

        std::shared_ptr<Order> getCanceledOrderFromKitchen(Waiter* waiter);

        std::shared_ptr<Order> getOrderFromKitchen(Waiter* waiter);

};

#endif