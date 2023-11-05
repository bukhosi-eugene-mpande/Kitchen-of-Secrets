#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include "backend/src/cooking/Kitchen.h"
#include "backend/src/sudo_accounting/Inventory.h"
#include "backend/src/reservation/ReservationSystem.h"
#include "backend/src/reservation/Receptionist.h"

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
    public:
        PlayerInteraction(std::shared_ptr<Kitchen> kitchen, std::shared_ptr<Inventory> inventory, std::shared_ptr<ReservationSystem> reservationSystem, std::shared_ptr<Receptionist> receptionist, std::shared_ptr<Waiter> waiter);
        
        ~PlayerInteraction();

        void sendOrderToKitchen(std::shared_ptr<Order> order);

        std::shared_ptr<Order> getOrderFromKitchen(std::shared_ptr<Waiter> waiter);

        std::shared_ptr<Order> getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter);

        void setKitchen(std::shared_ptr<Kitchen> kitchen);

        bool requestIngredients(std::unordered_map<std::string,int> ingredients);

        void notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter);

        void notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter);

        void setInventory(std::shared_ptr<Inventory> inventory);

        void notifyPlayerOfChangeInMood();

        void clearOutTable(std::shared_ptr<Table> table);

        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);

        std::shared_ptr<Section> getGeneralSection();

        std::shared_ptr<Section> getPrivateSection();

        std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();

        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);
}  

/*
#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include "backend/src/accounting/AccountingSystem.h"
#include "backend/src/customercare/Customer.h"
#include "backend/src/customercare/CustomerCareSystem.h"
#include "backend/src/cooking/CookingSystem.h"
#include "backend/src/cooking/Kitchen.h"
#include "backend/src/cooking/Order.h"
#include "backend/src/cooking/Inventory.h"
#include "backend/src/reservation/ReservationSystem.h"
#include "GameComponent.h"

#include <vector>
#include <queue>
#include <memory>

class PlayerInteraction : public GameComponent {
    private:
        std::shared_ptr<AccountingSystem> accountingSystem;
        std::shared_ptr<CookingSystem> cookingSystem;
        std::shared_ptr<CustomerCareSystem> customerCareSystem;
        std::shared_ptr<Kitchen> kitchen;
        std::shared_ptr<Order> order;
        std::shared_ptr<Inventory> inventory;
        std::shared_ptr<ReservationSystem> reservationSystem;
    public:
        PlayerInteraction(std::shared_ptr<Engine> engine, std::shared_ptr<AccountingSystem> accountingSystem, std::shared_ptr<CookingSystem> cookingSystem, std::shared_ptr<CustomerCareSystem> customerCareSystem, std::shared_ptr<Kitchen> kitchen, std::shared_ptr<Inventory> inventory, std::shared_ptr<ReservationSystem> reservationSystem, std::shared_ptr<Order> order);
        ~PlayerInteraction();
        void payment(std::vector<std::shared_ptr<Customer>> customers);
        void addToTab(std::vector<std::shared_ptr<Customer>> customers);
        void closeTab(std::vector<std::shared_ptr<Customer>> customers);
        void sendOrderToKitchen(std::shared_ptr<Order> order);
        std::shared_ptr<Order> getOrderFromKitchen(std::shared_ptr<Waiter> waiter);
        std::shared_ptr<Order> getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter);
        bool requestIngredients(std::unordered_map<std::string,int> ingredients);
        void notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter);
        void notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter);
        void purchaseInventory(std::unordered_map<std::string, int> ingredients);
        void sendOrderToKitchen(std::shared_ptr<Order> order);
        void seatCustomers(std::vector<std::shared_ptr<Customer>> customers);
};

#endif
*/