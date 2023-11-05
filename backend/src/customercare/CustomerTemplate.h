#ifndef CustomerTemplate_H
#define CustomerTemplate_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

class SatisfactionState;
class Reservation;
class Waiter;
class Management;
class Menu;
class Order;

class CustomerTemplate{
    protected:
        std::vector<std::shared_ptr<CustomerTemplate>> guests;
        std::shared_ptr<Reservation> reservation;
        std::shared_ptr<Management> management;
        std::string name;
        std::shared_ptr<SatisfactionState> Mood;
        std::unordered_map<std::string,int> order;
        std::unordered_map<std::string,int> BevarageOrder;
        std::unordered_map<std::string,int> FoodOrder;
        std::shared_ptr<Order> finishedOrder;
        std::string DesiredSection;
        int numGuests;
        double totalBill;
        bool readyToOrder;
        bool ordered;
        bool hasGuests;
        bool isMain;

    public:
        CustomerTemplate(std::string name, std::shared_ptr<Management> management);

        ~CustomerTemplate();

        std::shared_ptr<SatisfactionState> getMood();

        double calculateFinalBill(double bill);

        void setMood(std::shared_ptr<SatisfactionState> Mood);

        std::unordered_map<std::string,int> getOrder();

        std::string getName();

        bool IsReadyToOrder();

        std::unordered_map<std::string,int> requestBeverageOrder(std::shared_ptr<Menu> menu);

        std::unordered_map<std::string,int> requestFoodOrder(std::shared_ptr<Menu> menu);

        std::unordered_map<std::string,int> generateBeverageOrder(std::shared_ptr<Menu> menu);

        std::unordered_map<std::string,int> generateFoodOrder(std::shared_ptr<Menu> menu);

        void setOrder(std::unordered_map<std::string,int> order);

        void setBeverageOrder(std::unordered_map<std::string,int> order);

        void setFoodOrder(std::unordered_map<std::string,int> order);

        std::unordered_map<std::string,int> getBeverageOrder();

        std::unordered_map<std::string,int> getFoodOrder();

        bool getOrdered();

        void setOrdered(bool ordered);

        std::shared_ptr<Order> getFinishedOrder();

        void setFinishedOrder(std::shared_ptr<Order> order);

        void setTotalBill(double bill);

        double getTotalBill();

        void setReadyToOrder(bool readyToOrder);

        void console();

        void anger();

        void notifyManagement();

        void leave();

        std::shared_ptr<Reservation> getReservation();

        void setReservation(std::shared_ptr<Reservation> reservation);

        std::shared_ptr<Management> getManagement();

        void setManagement(std::shared_ptr<Management> management);

        std::shared_ptr<CustomerTemplate> this_to_shared();

        bool getHasGuests();

        void setHasGuests(bool hasGuests);

        bool getIsMain();

        void setIsMain(bool isMain);

        int getNumGuests();

        void setNumGuests(int numGuests);

        void requestReservation();

        void addGuest(std::shared_ptr<CustomerTemplate> guest);

        std::vector<std::shared_ptr<CustomerTemplate>> getGuests();

        std::string getDesiredSection();

        void setDesiredSection(std::string section);

        void requestToBeSeated();

        int generateRandomNum(int min, int max);



};
#endif