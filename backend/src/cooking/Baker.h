/**
 * @file Baker.h
 * @brief Contains the declaration of the Baker class.
 */

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
 * @brief Represents a baker chef in the kitchen responsible for preparing bakery items.
 */
class Baker : public StationChef {
public:
    /**
     * @brief Constructor for the Baker class.
     * @param kitchen Pointer to the kitchen where the baker works.
     */
    Baker(Kitchen* kitchen);

    /**
     * @brief Destructor for the Baker class.
     */
    ~Baker();

    /**
     * @brief Prepare an order by the baker chef.
     * @param order A shared pointer to the order to be prepared.
     */
    void prepareOrder(std::shared_ptr<Order> order) override;

    /**
     * @brief Set the next chef in the chain of responsibility.
     */
    void setNextChef() override;
};

#endif
