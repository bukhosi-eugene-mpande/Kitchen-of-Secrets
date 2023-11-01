#ifndef Happy_H
#define Happy_H

#include <memory>
#include <string>
#include "SatisfactionState.h"
class Happy : public SatisfactionState{
    public:
        Happy(std::shared_ptr<CustomerTemplate> customer);
        void console();
        void anger();
};
#endif