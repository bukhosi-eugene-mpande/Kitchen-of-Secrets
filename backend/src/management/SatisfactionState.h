#ifndef SATISFACTION_STATE_H
#define SATISFACTION_STATE_H

#include "Customer.h"

#include <memory>
#include <string>

class SatisfactionState {
    private:
        Customer* customer;
    public:
        SatisfactionState();
        ~SatisfactionState();
        SatisfactionState* getMood();
        virtual void setMood(SatisfactionState* satisfactionState) = 0;
        virtual void helpMe() = 0;
        virtual std::string getStateName() = 0;  
};

#endif

