#ifndef Neutral_H
#define Neutral_H


#include <iostream>
#include "SatisfactionState.h"

class Neutral : public SatisfactionState {

    public:
        Neutral();
        ~Neutral();
        double getTipPercentage();
        void appease(Customer* customer);
        void upset(Customer* customer);
};

#endif