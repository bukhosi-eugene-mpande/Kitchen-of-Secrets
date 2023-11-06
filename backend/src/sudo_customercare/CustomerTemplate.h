#ifndef CUSTOMER_TEMPLATE_H
#define CUSTOMER_TEMPLATE_H

#include "backend/src/management/GameComponent.h"
#include "backend/src/management/PlayerInteraction.h"

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

class SatisfactionState;
class Reservation;
class Waiter;
<<<<<<< HEAD:backend/src/customercare/CustomerTemplate.h
// class Management;
class PlayerInteraction;
=======
class Management;
class Menu;
class Order;
>>>>>>> kitchen-Intergration:backend/src/sudo_customercare/CustomerTemplate.h

class CustomerTemplate : public GameComponent {
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
        int numberOfGuests;
        double totalBill;
        bool isDoneEating;
        std::string paymentType;
        bool readyToOrder;
        bool readyToPay;
        bool ordered;
        bool hasGuests;
        bool isMain;
<<<<<<< HEAD:backend/src/customercare/CustomerTemplate.h
=======
        bool isEating;

>>>>>>> kitchen-Intergration:backend/src/sudo_customercare/CustomerTemplate.h
    public:
        CustomerTemplate(std::shared_ptr<Engine> engine, std::string name, std::shared_ptr<PlayerInteraction> management);
        ~CustomerTemplate();
        std::shared_ptr<SatisfactionState> getMood();
        double calculateFinalBill(double bill);
<<<<<<< HEAD:backend/src/customercare/CustomerTemplate.h
=======

        //make customer eat
        bool getIsEating();

        void setIsEating();

>>>>>>> kitchen-Intergration:backend/src/sudo_customercare/CustomerTemplate.h
        void setMood(std::shared_ptr<SatisfactionState> Mood);
        std::unordered_map<std::string,int> getOrder();
        std::string getName();
<<<<<<< HEAD:backend/src/customercare/CustomerTemplate.h
        bool IsReadyToOrder();
        void setOrder(std::unordered_map<std::string,int> order);
=======

        std::string getPaymentType();

        std::string setpaymentType(std::string getPaymentType);

        bool IsReadyToOrder();

        bool IsReadyToPay();

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

>>>>>>> kitchen-Intergration:backend/src/sudo_customercare/CustomerTemplate.h
        double getTotalBill();
        void setReadyToOrder(bool readyToOrder);
<<<<<<< HEAD:backend/src/customercare/CustomerTemplate.h
=======

        void setReadyToPay(bool readyToPay);

>>>>>>> kitchen-Intergration:backend/src/sudo_customercare/CustomerTemplate.h
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
<<<<<<< HEAD:backend/src/customercare/CustomerTemplate.h
=======

        void setNumGuests(int numGuests);

>>>>>>> kitchen-Intergration:backend/src/sudo_customercare/CustomerTemplate.h
        void requestReservation();
        void addGuest(std::shared_ptr<CustomerTemplate> guest);
        std::vector<std::shared_ptr<CustomerTemplate>> getGuests();
        std::string getDesiredSection();
        void setDesiredSection(std::string section);
        void requestToBeSeated();
<<<<<<< HEAD:backend/src/customercare/CustomerTemplate.h
        virtual void sendEvent() = 0;
        virtual void receiveEvent(std::string event) = 0;
=======

        int generateRandomNum(int min, int max);

        void setPaymentType(std::string paymentType);

        void setDoneEating(bool isDoneEating);

        bool getDoneEating();




>>>>>>> kitchen-Intergration:backend/src/sudo_customercare/CustomerTemplate.h
};
#endif