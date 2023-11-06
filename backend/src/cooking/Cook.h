/**
 * @file Cook.h
 * @brief Contains the declaration of the Cook class.
 */

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
 * @brief Represents a cook in the kitchen responsible for preparing food orders.
 */
class Cook : public StationChef {
public:
    /**
     * @brief Constructor for the Cook class.
     * @param kitchen Pointer to the kitchen where the cook works.
     */
    Cook(Kitchen* kitchen);

    /**
     * @brief Destructor for the Cook class.
     */
    ~Cook();

    /**
     * @brief Prepare an order by cooking the required food items.
     * @param order A shared pointer to the order that needs to be prepared.
     */
    void prepareOrder(std::shared_ptr<Order> order) override;

    /**
     * @brief Set the next chef in the chain of responsibility.
     */
    void setNextChef() override;
};

#endif
