#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerTemplate.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>

class SatisfactionState;

class Customer: public CustomerTemplate{
    private:
        std::shared_ptr<SatisfactionState> Mood;
        std::vector<Customer> guests;
        bool isMainGuest;
        double totalBill;

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
        

};
#endif