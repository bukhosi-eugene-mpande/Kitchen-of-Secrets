#ifndef Management_H
#define Management_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class Waiter;
class Accounting;
class Kitchen;
class Inventory;
class ReservationSystem;
class Receptionist;
class Section;
class CustomerTemplate;
class Table;
class Drink;
class Cuisine;

class Management {
    private:
        std::shared_ptr<Kitchen> kitchen;
        std::shared_ptr<Inventory> inventory;
        std::shared_ptr<ReservationSystem> reservationSystem;
        std::shared_ptr<Receptionist> receptionist;
        std::shared_ptr<Accounting> accounting;
        bool billReceived;
        

    public:
        Management();

        ~Management();

        bool hasReceivedBill(){
            return this->billReceived=true;
        }

        void sendOrderToKitchen(std::shared_ptr<Order> order);

        std::shared_ptr<Order> getOrderFromKitchen(Waiter* waiter);

        std::shared_ptr<Order> getCanceledOrderFromKitchen(Waiter* waiter);

        void setKitchen(std::shared_ptr<Kitchen> kitchen);

        bool requestIngredients(std::unordered_map<std::string,int> ingredients);

        void notifyWaiterOfCancellation(Waiter* waiter);

        void notifyWaiterOfCompletion(Waiter* waiter);

        void setInventory(std::shared_ptr<Inventory> inventory);

        void pay(std::string paymentType, double bill);

        void notifyPlayerOfChangeInMood();

        void clearOutTable(std::shared_ptr<Table> table);

        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);

        std::shared_ptr<Section> getGeneralSection();

        std::shared_ptr<Section> getPrivateSection();

        std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();

        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);

        std::shared_ptr<Drink> getDrink(std::string name);

        std::shared_ptr<Cuisine> getCusine(std::string name);

        std::unordered_map<int,std::string> getDrinksMenu();

        std::unordered_map<int,std::string> getCuisineMenu();

};

#endif