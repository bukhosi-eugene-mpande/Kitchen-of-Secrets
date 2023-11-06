/**
 * @file DeputyHeadChef.h
 * @brief Contains the declaration of the DeputyHeadChef class, derived from the StationChef class.
 */

#ifndef DEPUTYHEADCHEF_H
#define DEPUTYHEADCHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"
#include "Chef.h"

class Management;

/**
 * @class DeputyHeadChef
 * @brief Represents a deputy head chef in the kitchen.
 *
 * The DeputyHeadChef class is derived from the StationChef class and provides
 * additional functionality for managing orders and interacting with the kitchen's management.
 */
class DeputyHeadChef : public StationChef {
private:
    PlayerInteraction* management; ///< A pointer to the management interface.
    bool flag; ///< A flag used for internal management.

public:
    /**
     * @brief Constructor for the DeputyHeadChef class.
     * @param kitchen A pointer to the kitchen where the deputy head chef works.
     */
    DeputyHeadChef(Kitchen* kitchen);

    /**
     * @brief Destructor for the DeputyHeadChef class.
     */
    ~DeputyHeadChef();

    /**
     * @brief Prepare an order.
     * @param order A shared pointer to the order to be prepared.
     */
    void prepareOrder(std::shared_ptr<Order> order);

    /**
     * @brief Set the next chef in the kitchen.
     */
    void setNextChef();

    /**
     * @brief Cancel an order.
     * @param order A shared pointer to the order to be canceled.
     */
    void cancelOrder(std::shared_ptr<Order> order);

    /**
     * @brief Finish preparing an order.
     * @param order A shared pointer to the order that is ready for serving.
     */
    void finishOrder(std::shared_ptr<Order> order);

    /**
     * @brief Get a pointer to the kitchen where the deputy head chef works.
     * @return A pointer to the kitchen.
     */
    Kitchen* getKitchen() const;

    /**
     * @brief Set the management interface for the deputy head chef.
     */
    void setManagement();
};

#endif
