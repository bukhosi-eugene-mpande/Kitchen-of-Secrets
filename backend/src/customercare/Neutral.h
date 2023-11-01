#ifndef Neutral_H
#define Neutral_H

#include <memory>
#include <string>
#include <algorithm>
#include "SatisfactionState.h"
class Neutral : public SatisfactionState{
    public:
        Neutral(CustomerTemplate* customer);
        void console();
        void anger();
};

#endif