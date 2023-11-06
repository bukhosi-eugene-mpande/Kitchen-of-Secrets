/**
 * @file GrillChef.h
 * @brief Contains the declaration of the GrillChef class, derived from the StationChef class.
 */

#ifndef GRILL_CHEF_H
#define GRILL_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

/**
 * @class GrillChef
 * @brief Represents a chef specializing in grilling, derived from the StationChef class.
 *
 * The GrillChef class is derived from the StationChef class and represents a chef who specializes in grilling
 * food items. It handles the preparation of orders assigned to this station.
 */
class GrillChef : public StationChef {
public:
    /**
     * @brief Constructor for the GrillChef class.
     * @param kitchen A pointer to the Kitchen where the GrillChef works.
     */
    GrillChef(Kitchen* kitchen);

    /**
     * @brief Destructor for the GrillChef class.
     */
    ~GrillChef();

    /**
     * @brief Prepare an order assigned to the GrillChef station.
     * @param order A shared pointer to the Order object to be prepared.
     */
    void prepareOrder(std::shared_ptr<Order> order) override;

    /**
     * @brief Set the next chef in the workflow after GrillChef.
     */
    void setNextChef() override;
};

#endif
