#ifndef VeryUnhappy_H
#define VeryUnhappy_H

#include <memory>
#include <string>
#include "SatisfactionState.h"

class VeryUnhappy : public SatisfactionState{
    public:
        VeryUnhappy(std::shared_ptr<CustomerTemplate> customer);
        void console();
        void anger();
};
#endif