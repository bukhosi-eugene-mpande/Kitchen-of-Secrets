#ifndef COOK_H
#define COOK_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

/**
 * @class Cook
 * @brief A class representing a cook in the kitchen.
 * 
 * This class inherits from StationChef and implements the prepareOrder and setNextChef methods.
 */
class Cook : public StationChef { 
    public:
        /**
         * @brief Construct a new Cook object
         * 
         * @param kitchen A pointer to the kitchen object.
         */
        Cook(Kitchen* kitchen);

        /**
         * @brief Destroy the Cook object
         * 
         */
        ~Cook();

        /**
         * @brief Prepare the given order.
         * 
         * This method overrides the prepareOrder method of the StationChef class.
         * 
         * @param order A shared pointer to the order to be prepared.
         */
        void prepareOrder(std::shared_ptr<Order> order) override;
        
        /**
         * @brief Set the next chef in the chain of responsibility.
         * 
         * This method overrides the setNextChef method of the StationChef class.
         * 
         */
        void setNextChef() override;
};

#endif