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
        Customer(std::shared_ptr<Engine> engine, std::shared_ptr<PlayerInteraction> management);
        ~Customer();
        virtual void sendEvent();
        virtual void receiveEvent(std::string event);
        
};
#endif