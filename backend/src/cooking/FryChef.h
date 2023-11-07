#ifndef FRY_CHEF_H
#define FRY_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

/**
 * @brief The FryChef class represents a chef who specializes in frying food.
 * 
 * This class inherits from the StationChef class and overrides its prepareOrder() and setNextChef() methods.
 */
class FryChef : public StationChef{
    public:
        /**
         * @brief Constructs a new FryChef object.
         * 
         * @param kitchen A pointer to the Kitchen object that this FryChef belongs to.
         */
        FryChef(Kitchen* kitchen);

        /**
         * @brief Destroys the FryChef object.
         */
        ~FryChef();

        /**
         * @brief Prepares the given order by frying the appropriate food items.
         * 
         * This method overrides the prepareOrder() method of the StationChef class.
         * 
         * @param order A shared pointer to the Order object to be prepared.
         */
        void prepareOrder(std::shared_ptr<Order> order) override;

        /**
         * @brief Sets the next chef in the cooking process.
         * 
         * This method overrides the setNextChef() method of the StationChef class.
         */
        void setNextChef() override;
};

#endif