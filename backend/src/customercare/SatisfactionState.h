#ifndef SATISFACTION_STATE_H
#define SATISFACTION_STATE_H

#include "Customer.h"

#include <string>

class SatisfactionState {
    public:
        SatisfactionState();
        virtual ~SatisfactionState();
        virtual void HelpMe(std::shared_ptr<Customer> mood, std::string complaints) = 0;
        virtual void timeLaps(std::shared_ptr<Customer> mood, std::string complaints) = 0;
        virtual double getTip() = 0;
        virtual std::string getStateName() = 0;
};
#endif