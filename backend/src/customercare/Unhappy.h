#ifndef Unhappy_H
#define Unhappy_H

#include <string>
#include "SatisfactionState.h"
#include <algorithm>
class Unhappy : public SatisfactionState{
    public:
        Unhappy(CustomerTemplate* customer);
        void console();
        void anger();

};
#endif