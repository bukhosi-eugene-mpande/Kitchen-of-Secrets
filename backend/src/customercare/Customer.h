/**
 * @file Customer.h
 * @brief Contains the declaration of the Customer class.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerTemplate.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include <unordered_map>

/**
 * @class Customer
 * @brief Represents a customer in the restaurant.
 *
 * The Customer class represents a customer in the restaurant. It is derived from the CustomerTemplate class and includes customer-specific behaviors and attributes.
 */
class Customer: public CustomerTemplate {
public:
    /**
     * @brief Constructor for the Customer class.
     * @param management A shared pointer to the player interaction management.
     */
    Customer(std::shared_ptr<PlayerInteraction> management);

    /**
     * @brief Destructor for the Customer class.
     */
    ~Customer();
};

#endif
