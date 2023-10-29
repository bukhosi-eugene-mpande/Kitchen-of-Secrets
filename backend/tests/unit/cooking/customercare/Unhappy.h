#ifndef Unhappy_H
#define Unhappy_H


#include <iostream>
#include "SatisfactionState.h"

class Unhappy : public SatisfactionState {

    public:
        Unhappy();
        ~Unhappy();
        double getTipPercentage();
        void appease(Customer* customer);
        void upset(Customer* customer);
};

#endif