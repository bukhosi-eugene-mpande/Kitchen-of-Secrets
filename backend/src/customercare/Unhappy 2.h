#ifndef UNHAPPY_H
#define UNHAPPY_H

#include "SatisfactionState.h"
#include "Customer.h"

#include <string>
#include <algorithm>

class Unhappy : public SatisfactionState
{
    public:
        Unhappy();
        ~Unhappy();
        void helpMe(std::shared_ptr<Customer> mood, std::string complaints);
        void timeLaps(std::shared_ptr<Customer> mood, std::string complaints);
        double getTip();
        std::string getStateName();
};
#endif