#ifndef HeadChef_H
#define HeadChef_H

#include <vector>
#include <string>
#include "SatisfactionState.h"
#include "Customer.h"

class HeadChef: public CustomerObserver{
    private:
    std::string name;
    Customer* customer;
    public:
    void updateCustomerMood();


};

#endif