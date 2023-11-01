#ifndef CustomerTemplate_H
#define CustomerTemplate_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>

class SatisfactionState;
class Reservation;
class Waiter;
class Management;

class CustomerTemplate{
    private:
        std::shared_ptr<Reservation> reservation;
        std::shared_ptr<Management> management;
        std::string name;
        std::shared_ptr<SatisfactionState> Mood;
        std::unordered_map<std::string,int> order;
        double totalBill;
        bool readyToOrder;

    public:
        CustomerTemplate(std::string name, std::shared_ptr<Management> management);

        ~CustomerTemplate();

        std::shared_ptr<SatisfactionState> getMood();

        double calculateFinalBill(double bill);

        void setMood(std::shared_ptr<SatisfactionState> Mood);

        std::shared_ptr<SatisfactionState> getMood();

        std::unordered_map<std::string,int> getOrder();

        void setOrder(std::unordered_map<std::string,int> order);

        double getTotalBill();

        void setReadyToOrder(bool readyToOrder);

        void console();

        void anger();

        void notifyManagement();

        void leave();

};
#endif