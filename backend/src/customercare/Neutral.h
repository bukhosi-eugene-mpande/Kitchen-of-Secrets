#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "SatisfactionState.h"

#include <string>
#include <algorithm>

class Neutral : public SatisfactionState {
    public:
        Neutral();
        ~Neutral();
        void helpMe(std::shared_ptr<Customer> mood, std::string complaints);
        void timeLaps(std::shared_ptr<Customer> mood, std::string complaints);
        double getTip();
        std::string getStateName();
};
#endif