#ifndef CUSTOMER_OBSERVER_H
#define CUSTOMER_OBSERVER_H

#include "Customer.h"

#include <memory>

class CustomerObserver {
    public:
        virtual void setMood(std::shared_ptr<SatisfactionState> satisfactionState) = 0;
};

#endif