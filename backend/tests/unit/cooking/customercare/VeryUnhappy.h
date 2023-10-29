#ifndef VeryUnhappy_H
#define VeryUnhappy_H


#include <iostream>
#include "SatisfactionState.h"

class VeryUnhappy : public SatisfactionState {

    public:
        VeryUnhappy();
        ~VeryUnhappy();
        double getTipPercentage();
        void appease(Customer* customer);
        void upset(Customer* customer);
};

#endif