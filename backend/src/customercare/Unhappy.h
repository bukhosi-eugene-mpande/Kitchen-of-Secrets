#ifndef Unhappy_H
#define Unhappy_H

#include <string>
#include <algorithm>

#include "SatisfactionState.h"

class Unhappy : public SatisfactionState{
    public:
        Unhappy(CustomerTemplate* customer);
        void console();
        void anger();

};
#endif