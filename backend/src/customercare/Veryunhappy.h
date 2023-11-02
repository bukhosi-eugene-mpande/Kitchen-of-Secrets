#ifndef VERY_UNHAPPY_H
#define VERY_UNHAPPY_H

#include "SatisfactionState.h"

#include <string>

class VeryUnhappy : public SatisfactionState
{
    public:
        VeryUnhappy();
        ~VeryUnhappy();
        void helpMe(std::shared_ptr<Customer> mood, std::string complaints);
        void timeLaps(std::shared_ptr<Customer> mood, std::string complaints);
        double getTip();
        std::string getStateName();
};
#endif