#ifndef HAPPY_H
#define HAPPY_H

#include <memory>
#include <string>
#include "SatisfactionState.h"
class Happy : public SatisfactionState {
    public:
        Happy(CustomerTemplate* customer);
        void console();
        void anger();
};
#endif