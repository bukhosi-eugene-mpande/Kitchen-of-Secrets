#ifndef BAKER_H
#define BAKER_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

/**
 * @class Baker
 * @brief A class representing a baker in the kitchen.
 * 
 * This class inherits from the StationChef class and overrides its pure virtual functions.
 * The Baker is responsible for preparing baked goods orders.
 */
class Baker : public StationChef {
    public:
        /**
         * @brief Constructs a new Baker object.
         * 
         * @param kitchen A pointer to the Kitchen object.
         */
        Baker(Kitchen* kitchen);

        /**
         * @brief Destroys the Baker object.
         */
        ~Baker();

        /**
         * @brief Prepares the given order.
         * 
         * @param order A shared pointer to the Order object.
         */
        void prepareOrder(std::shared_ptr<Order> order) override;
        
        /**
         * @brief Sets the next chef in the chain of responsibility.
         */
        void setNextChef() override;
};

#endif