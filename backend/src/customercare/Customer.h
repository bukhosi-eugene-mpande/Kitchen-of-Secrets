#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerTemplate.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include <unordered_map>

class SatisfactionState;
class Waiter;

class Customer: public CustomerTemplate {
    public:
        Customer(std::shared_ptr<PlayerInteraction> management);
        ~Customer();
        
};
#endif