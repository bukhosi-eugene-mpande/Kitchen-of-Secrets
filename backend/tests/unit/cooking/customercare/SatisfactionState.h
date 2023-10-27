#ifndef SatisfactionState_H
#define SatisfactionState_H


#include <iostream>
class Customer;

class SatisfactionState {
    private:
        double tipPercentage;
        std::string name;

    public:
        SatisfactionState(std::string name,double tipPercentage);
        ~SatisfactionState();
        double getTipPercentage();
        virtual void appease(Customer* customer) = 0;
        virtual void upset(Customer* customer) = 0;
};

#endif