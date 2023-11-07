#ifndef GRILL_CHEF_H
#define GRILL_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

/**
 * @brief The GrillChef class represents a chef that specializes in grilling food items.
 * 
 * This class inherits from the StationChef class and implements the prepareOrder and setNextChef methods.
 * The prepareOrder method prepares the order by grilling the food items, while the setNextChef method sets the next chef in the cooking process.
 */
class GrillChef : public StationChef{
    public:
        /**
         * @brief Constructs a new GrillChef object.
         * 
         * @param kitchen A pointer to the Kitchen object.
         */
        GrillChef(Kitchen* kitchen);

        /**
         * @brief Destroys the GrillChef object.
         */
        ~GrillChef();

        /**
         * @brief Prepares the order by grilling the food items.
         * 
         * @param order A shared pointer to the Order object.
         */
        void prepareOrder(std::shared_ptr<Order> order) override;

        /**
         * @brief Sets the next chef in the cooking process.
         */
        void setNextChef() override;
};

#endif