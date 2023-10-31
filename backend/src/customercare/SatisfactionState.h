#ifndef SATISFACTIONSTATE_H
#define SATISFACTIONSTATE_H

#include <memory>
#include <string>
#include "Customer.h"

class SatisfactionState{
    protected:
        std::shared_ptr<Customer> customer;
        double discount;
        double tip;
        std::string stateName;
    public:
        SatisfactionState(std::string stateName, std::shared_ptr<Customer> customer, double discount, double tip);
        virtual void console()=0;
        virtual void anger()=0;
        double calculateBill(double bill);
        std::string getStateName();
};
#endif