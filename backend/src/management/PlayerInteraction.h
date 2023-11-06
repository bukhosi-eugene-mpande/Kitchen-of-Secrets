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

class PlayerInteraction {

    private:
        std::shared_ptr<ReservationSystem> reservationSystem;

        std::shared_ptr<Receptionist> receptionist;

        std::shared_ptr<CustomerTemplate> customer;

        std::shared_ptr<Inventory> inventory;

        std::shared_ptr<Kitchen> kitchen;

        std::shared_ptr<Accounting> accounting;

        // std::shared_ptr<Waiter> waiter;

        //why do have a pointer to a class that a pure vitual function

    public:
        PlayerInteraction();
        
        ~PlayerInteraction();

        //interaction between customer and reservation

        void clearOutTable(std::shared_ptr<Table> table);

        void notifyPlayerOfChangeInMood();

        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);

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