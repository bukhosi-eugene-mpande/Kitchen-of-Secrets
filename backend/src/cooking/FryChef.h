/**
 * @file FryChef.h
 * @brief Contains the declaration of the FryChef class, derived from the StationChef class.
 */

#ifndef FRY_CHEF_H
#define FRY_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

/**
 * @class FryChef
 * @brief Represents a chef specializing in frying, derived from the StationChef class.
 *
 * The FryChef class is derived from the StationChef class and represents a chef who specializes in frying
 * food items. It handles the preparation of orders assigned to this station.
 */
class FryChef : public StationChef {
public:
    /**
     * @brief Constructor for the FryChef class.
     * @param kitchen A pointer to the Kitchen where the FryChef works.
     */
    FryChef(Kitchen* kitchen);

    /**
     * @brief Destructor for the FryChef class.
     */
    ~FryChef();

    /**
     * @brief Prepare an order assigned to the FryChef station.
     * @param order A shared pointer to the Order object to be prepared.
     */
    void prepareOrder(std::shared_ptr<Order> order) override;

    /**
     * @brief Set the next chef in the workflow after FryChef.
     */
    void setNextChef() override;
};

#endif
