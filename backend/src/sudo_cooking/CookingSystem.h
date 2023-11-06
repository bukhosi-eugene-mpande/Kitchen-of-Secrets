#ifndef COOKING_SYSTEM_H
#define COOKING_SYSTEM_H

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

class CookingSystem {
    private:
        std::shared_ptr<Kitchen> kitchen;
        std::shared_ptr<Inventory> inventory;
        std::shared_ptr<ReservationSystem> reservationSystem;
        std::shared_ptr<Receptionist> receptionist;

    public:
        CookingSystem();
        ~CookingSystem();
        std::shared_ptr<Kitchen> getKitchen();
        void setKitchen(std::shared_ptr<Kitchen> kitchen);
        std::shared_ptr<Inventory> getInventory();
        void setInventory(std::shared_ptr<Inventory> inventory);
<<<<<<<< HEAD:backend/src/cooking/CookingSystem.h
        void sendOrderToKitchen(std::shared_ptr<Order> order);
        std::shared_ptr<Order> getOrderFromKitchen(std::shared_ptr<Waiter> waiter);
        std::shared_ptr<Order> getCanceledOrderFromKitchen(std::shared_ptr<Waiter> waiter);
        bool requestIngredients(std::unordered_map<std::string,int> ingredients);
        void notifyWaiterOfCancellation(std::shared_ptr<Waiter> waiter);
        void notifyWaiterOfCompletion(std::shared_ptr<Waiter> waiter);
========

        void notifyPlayerOfChangeInMood();

        void clearOutTable(std::shared_ptr<Table> table);

        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);

        std::shared_ptr<Section> getGeneralSection();

        std::shared_ptr<Section> getPrivateSection();

        std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();

        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);

>>>>>>>> kitchen-Intergration:backend/src/sudo_management/Management.h
};

#endif