#ifndef Happy_H
#define Happy_H

#include <memory>
#include <string>
#include "SatisfactionState.h"
class Happy : public SatisfactionState{
    public:
        Happy(CustomerTemplate* customer);
        void console();
        void anger();
};
#endif