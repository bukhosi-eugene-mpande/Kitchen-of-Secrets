#ifndef Unhappy_H
#define Unhappy_H

#include <string>
#include "SatisfactionState.h"
#include <algorithm>
class Unhappy : public SatisfactionState{
    public:
        Unhappy(std::shared_ptr<CustomerTemplate> customer);
        void console();
        void anger();

};
#endif