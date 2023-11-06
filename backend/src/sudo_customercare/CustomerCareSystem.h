#ifndef CUSTOMER_CARE_SYSTEM_H
#define CUSTOMER_CARE_SYSTEM_H

#include "CustomerObserver.h"

#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class CustomerCareSystem {
    private:
        std::vector<std::shared_ptr<CustomerObserver>> customerObserverList;
    public:
        void attach(std::shared_ptr<CustomerObserver> customerObserver);
        void detach(std::shared_ptr<CustomerObserver> customerObserver);
        void notify();
};
#endif