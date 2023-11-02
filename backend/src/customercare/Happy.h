#ifndef HAPPY_H
#define HAPPY_H

#include "SatisfactionState.h"

#include <string>

class Happy : public SatisfactionState {
    public:
        Happy();
        ~Happy();
        void helpMe(std::shared_ptr<Customer> mood, std::string complaints);
        void timeLaps(std::shared_ptr<Customer> mood, std::string complaints);
        double getTip();
        std::string getStateName();
};
#endif