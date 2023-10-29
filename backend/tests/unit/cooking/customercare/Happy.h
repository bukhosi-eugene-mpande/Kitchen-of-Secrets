#ifndef Happy_H
#define Happy_H


#include <iostream>
#include "SatisfactionState.h"

class Happy : public SatisfactionState {

    public:
        Happy();
        ~Happy();
        double getTipPercentage();
        void appease(Customer* customer);
        void upset(Customer* customer);
};

#endif