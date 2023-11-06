#ifndef WAITER_H
#define WAITER_H
#include "CustomerObserver.h"
#include "SatisfactionState.h"
#include "Customer.h"

class Waiter: public CustomerObserver{
    private:
        Customer* customer;
    public:
        void updateCustomerMood();
};
#endif