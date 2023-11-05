#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include "backend/src/cooking/Kitchen.h"
#include "backend/src/sudo_accounting/Inventory.h"
#include "backend/src/reservation/ReservationSystem.h"
#include "backend/src/reservation/Receptionist.h"
#include "backend/src/customercare/Customer.h"
#include "backend/src/management/Engine.h"
#include "backend/src/ordering/MenuItem.h"

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class Waiter;
class Kitchen;
class Inventory;
class ReservationSystem;
class Receptionist;
class Section;
class CustomerTemplate;
class Table;

class PlayerInteraction {
    private:
        std::shared_ptr<Kitchen> kitchen;
        std::shared_ptr<Inventory> inventory;
        std::shared_ptr<ReservationSystem> reservationSystem;
        std::shared_ptr<Receptionist> receptionist;
        std::shared_ptr<Waiter> waiter;
        std::shared_ptr<Customer> customer;
        std::shared_ptr<Engine> engine;
    public:
        PlayerInteraction(std::shared_ptr<Kitchen> kitchen, std::shared_ptr<Inventory> inventory, std::shared_ptr<ReservationSystem> reservationSystem, std::shared_ptr<Receptionist> receptionist, std::shared_ptr<Waiter> waiter, std::shared_ptr<Customer> customer, std::shared_ptr<Engine> engine);
        
        ~PlayerInteraction();

        void sendOrderToKitchen();

        std::shared_ptr<Order> getOrderFromKitchen();

        std::shared_ptr<Order> getCanceledOrderFromKitchen();

        bool requestIngredients(std::unordered_map<std::string,int> ingredients);

        void notifyWaiterOfCancellation();

        void notifyWaiterOfCompletion();

        void notifyPlayerOfChangeInMood();

        void clearOutTable(std::shared_ptr<Table> table);

        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);

        std::shared_ptr<Section> getGeneralSection();

        std::shared_ptr<Section> getPrivateSection();

        std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();

        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);
}  