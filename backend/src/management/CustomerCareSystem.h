#ifndef CUSTOMER_CARE_SYSTEM_H
#define CUSTOMER_CARE_SYSTEM_H

#include "CustomerObserver.h"

#include <list>
#include <memory>

class CustomerCareSystem {
    private:
        std::list<CustomerObserver*> customerObserverList;
    public:
        void attach(CustomerObserver* CustomerObserver);
        void detach(CustomerObserver* CustomerObserver);
        void notify();
};

#endif