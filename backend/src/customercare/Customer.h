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

/**
 * @brief The Customer class represents a customer in the restaurant.
 * 
 * This class inherits from the CustomerTemplate class and provides additional functionality
 * for managing customer interactions.
 */
class Customer: public CustomerTemplate {
    public:
        /**
         * @brief Constructs a new Customer object with the given management interface.
         * 
         * @param management A shared pointer to a PlayerInteraction object that will be used
         *                   to manage interactions with the customer.
         */
        Customer(std::shared_ptr<PlayerInteraction> management);

        /**
         * @brief Destroys the Customer object.
         * 
         * This function is responsible for cleaning up any resources used by the Customer object.
         */
        ~Customer();
        
};
#endif