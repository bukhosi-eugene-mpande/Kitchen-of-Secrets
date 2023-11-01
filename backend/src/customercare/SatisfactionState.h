#ifndef SATISFACTIONSTATE_H
#define SATISFACTIONSTATE_H

#include <memory>
#include <string>
#include "CustomerTemplate.h"

class SatisfactionState{
    protected:
        CustomerTemplate* customer;
        double discount;
        double tip;
        std::string stateName;
    public:
        SatisfactionState(std::string stateName, CustomerTemplate* customer, double discount, double tip);
        void setCustomer(CustomerTemplate* customer);
        CustomerTemplate* getCustomer();
        virtual void console()=0;
        virtual void anger()=0;
        double calculateBill(double bill);
        std::string getStateName();
};
#endif