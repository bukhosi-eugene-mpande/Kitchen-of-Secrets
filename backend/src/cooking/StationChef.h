/**
 * @file StationChef.h
 * @brief Contains the declaration of the StationChef class.
 */

#ifndef STATION_CHEF_H
#define STATION_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

/**
 * @class StationChef
 * @brief Represents a chef responsible for a specific station in the kitchen.
 *
 * The StationChef class represents a chef responsible for a specific station in the kitchen. Station chefs are in charge of preparing orders for their respective stations and coordinating with other chefs.
 */
class StationChef : public Chef {
protected:
    std::shared_ptr<StationChef> nextStationChef; /**< A pointer to the next station chef in the kitchen. */

public:
    /**
     * @brief Constructor for the StationChef class.
     * @param kitchen A pointer to the kitchen where the chef works.
     * @param name The name of the chef.
     */
    StationChef(Kitchen* kitchen, std::string name);

    /**
     * @brief Destructor for the StationChef class.
     */
    ~StationChef();

    /**
     * @brief Prepare an order for the chef's station.
     * @param order A shared pointer to the order to be prepared.
     */
    virtual void prepareOrder(std::shared_ptr<Order> order) = 0;

    /**
     * @brief Set the next chef responsible for the next station.
     */
    virtual void setNextChef() = 0;

    /**
     * @brief Get the next station chef.
     * @return A shared pointer to the next station chef.
     */
    std::shared_ptr<StationChef> getNextChef() const;

    /**
     * @brief Set the next station chef.
     * @param nextChef A shared pointer to the next station chef.
     */
    void setNextChefAgain(std::shared_ptr<StationChef> nextChef);
};

#endif
