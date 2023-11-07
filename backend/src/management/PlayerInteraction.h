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
 * @brief The PlayerInteraction class represents the interaction between the player and the game.
 * 
 * This class is responsible for managing the interaction between the player and the game. It contains 
 * methods for handling customer reservations, seating, ordering, and payment. It also manages the 
 * inventory, kitchen, and accounting systems.
 */
class PlayerInteraction {

    private:
        std::shared_ptr<ReservationSystem> reservationSystem;

        std::shared_ptr<Receptionist> receptionist;

        std::shared_ptr<CustomerTemplate> customer;

        std::shared_ptr<Inventory> inventory;

        std::shared_ptr<Kitchen> kitchen;

        std::shared_ptr<Accounting> accounting;

        //why do have a pointer to a class that has a pure vitual function

    public:
        /**
         * @brief Construct a new Player Interaction object
         * 
         */
        PlayerInteraction();
        
        /**
         * @brief Destroy the Player Interaction object
         * 
         */
        ~PlayerInteraction();

        //interaction between customer and reservation

        /**
         * @brief Clears out a table after a customer has left
         * 
         * @param table The table to clear out
         */
        void clearOutTable(std::shared_ptr<Table> table);

        /**
         * @brief Notifies the player of a change in mood
         * 
         */
        void notifyPlayerOfChangeInMood();

        /**
         * @brief Requests a reservation for a customer
         * 
         * @param customer The customer requesting the reservation
         * @param section The section of the restaurant for the reservation
         */
        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);

        /**
         * @brief Requests to be seated at a table
         * 
         * @param customer The customer requesting to be seated
         */
        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);

        // interactions between the customer and the waiter

        /**
         * @brief Notifies the waiter of a cancellation
         * 
         * @param waiter The waiter to notify
         */
        void notifyWaiterOfCancellation(Waiter* waiter);

        /**
         * @brief Notifies the waiter of a completion
         * 
         * @param waiter The waiter to notify
         */
        void notifyWaiterOfCompletion(Waiter* waiter);

        /**
         * @brief Gets the general section of the restaurant
         * 
         * @return std::shared_ptr<Section> The general section of the restaurant
         */
        std::shared_ptr<Section> getGeneralSection();

        /**
         * @brief Gets the private section of the restaurant
         * 
         * @return std::shared_ptr<Section> The private section of the restaurant
         */
        std::shared_ptr<Section> getPrivateSection();

        /**
         * @brief Requests ingredients from the inventory
         * 
         * @param ingredients The ingredients to request
         * @return true If the ingredients are available
         * @return false If the ingredients are not available
         */
        bool requestIngredients(std::unordered_map<std::string,int> ingredients);
        
        /**
         * @brief Sends an order to the kitchen
         * 
         * @param order The order to send
         */
        void sendOrderToKitchen(std::shared_ptr<Order> order);  

        /**
         * @brief Gets an order from the kitchen
         * 
         * @return std::shared_ptr<Order> The order from the kitchen
         */
        std::shared_ptr<Order> getOrderFromKitchen();

        /**
         * @brief Gets a canceled order from the kitchen
         * 
         * @return std::shared_ptr<Order> The canceled order from the kitchen
         */
        std::shared_ptr<Order> getCanceledOrderFromKitchen();

        /**
         * @brief Gets a list of customers
         * 
         * @return std::vector<std::shared_ptr<CustomerTemplate>> The list of customers
         */
        std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();

        /**
         * @brief Pays the bill
         * 
         * @param payment The payment method
         * @param bill The amount to pay
         * @return std::string The payment confirmation
         */
        std::string pay(std::string payment,double bill);

        /**
         * @brief Gets the cuisine menu
         * 
         * @return std::unordered_map<int,std::string> The cuisine menu
         */
        std::unordered_map<int,std::string> getCuisineMenu();

        /**
         * @brief Gets the drinks menu
         * 
         * @return std::unordered_map<int,std::string> The drinks menu
         */
        std::unordered_map<int,std::string> getDrinksMenu();

        /**
         * @brief Gets a cuisine by name
         * 
         * @param name The name of the cuisine
         * @return std::shared_ptr<Cuisine> The cuisine
         */
        std::shared_ptr<Cuisine> getCusine(std::string name);

        /**
         * @brief Gets a drink by name
         * 
         * @param name The name of the drink
         * @return std::shared_ptr<Drink> The drink
         */
        std::shared_ptr<Drink> getDrink(std::string name);

        /**
         * @brief Sets the inventory system
         * 
         * @param inventory The inventory system
         */
        void setInventory(std::shared_ptr<Inventory> inventory);

        /**
         * @brief Sets the kitchen system
         * 
         * @param kitchen The kitchen system
         */
        void setKitchen(std::shared_ptr<Kitchen> kitchen);

        /**
         * @brief Gets a canceled order from the kitchen for a specific waiter
         * 
         * @param waiter The waiter
         * @return std::shared_ptr<Order> The canceled order from the kitchen
         */
        std::shared_ptr<Order> getCanceledOrderFromKitchen(Waiter* waiter);

        /**
         * @brief Gets an order from the kitchen for a specific waiter
         * 
         * @param waiter The waiter
         * @return std::shared_ptr<Order> The order from the kitchen
         */
        std::shared_ptr<Order> getOrderFromKitchen(Waiter* waiter);

};

#endif