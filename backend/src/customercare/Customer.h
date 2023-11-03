#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerCareSystem.h"
#include "GameComponent.h"
#include "backend/src/accounting/Billing/Billing.h"
#include "backend/src/accounting/Tab/Tab.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class SatisfactionState;

class Customer: public CustomerCareSystem, public GameComponent {
    private:
        std::shared_ptr<SatisfactionState> mood;
        std::shared_ptr<std::vector<std::string>> complaints;
        std::shared_ptr<Billing> bill;
        std::shared_ptr<Tab> tab; 
        double totalBill;
        double totalTab;
    public:
        Customer(std::shared_ptr<Engine> engine);
        ~Customer();
        std::shared_ptr<SatisfactionState> getMood();
        void setMood(std::shared_ptr<SatisfactionState> Mood);
        std::shared_ptr<std::vector<std::string>> getComplaints();
        void setComplaints(std::shared_ptr<std::vector<std::string>> complaints);
        std::shared_ptr<Billing> getBill();
        void setBill(std::shared_ptr<Billing> bill);
        std::shared_ptr<Tab> getTab();
        void setTab(std::shared_ptr<Tab> tab);
        double getTip();
        double getTotalBill();
        void setTotalBill(double totalBill);
        double getTotalTab();
        void setTotalTab(double tabAmount);
        void closeTab();
        void makePayment();
        void helpMe();
        void timeLaps();
        virtual void sendEvent();
        virtual void receiveEvent(std::string event);
        void receiveNotification();
        void checkOut();
        void cancelOrder();
        std::string toString();
};
#endif