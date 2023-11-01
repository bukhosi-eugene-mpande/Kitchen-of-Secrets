#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerTemplate.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include <unordered_map>

class SatisfactionState;
class Waiter;

class Customer: public CustomerTemplate{
    private:
        std::shared_ptr<SatisfactionState> Mood;
        std::vector<Customer> guests;
        bool isMainGuest;
        double totalBill;
        int tableNumber;

    public:
        Customer();
        ~Customer();
        std::shared_ptr<SatisfactionState> getMood();
        void setMood(std::shared_ptr<SatisfactionState> Mood);
        double getBill(double Bill);
        void setIsMainGuest(bool isMainGuest);
        bool getIsMainGuest();
        void addGuest(Customer guest);
        std::vector<Customer> getGuests();
        void setTableNumber(int tableNumber);
        std::unordered_map<std::string,int> chooseBeverages(std::shared_ptr<Waiter> waiter);
        std::unordered_map<std::string,int> chooseDishes(std::shared_ptr<Waiter> waiter);
        

};
#endif