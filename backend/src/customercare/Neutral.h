#ifndef Neutral_H
#define Neutral_H

#include <memory>
#include <string>
#include <algorithm>
#include "SatisfactionState.h"
class Neutral : public SatisfactionState{
    public:
        Neutral(std::shared_ptr<Customer> customer);
        void console();
        void anger();
};

#endif