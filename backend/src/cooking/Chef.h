/**
 * @file Chef.h
 * @brief Contains the declaration of the Chef class.
 */

#ifndef CHEF_H
#define CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"

/**
 * @class Chef
 * @brief Represents a chef in the kitchen responsible for preparing food items.
 */
class Chef {
protected:
    Kitchen* kitchen; ///< Pointer to the kitchen where the chef works.
    std::string name; ///< The name of the chef.

public:
    /**
     * @brief Constructor for the Chef class.
     * @param name The name of the chef.
     * @param kitchen Pointer to the kitchen where the chef works.
     */
    Chef(std::string name, Kitchen* kitchen);

    /**
     * @brief Destructor for the Chef class.
     */
    ~Chef();

    /**
     * @brief Get the name of the chef.
     * @return The name of the chef.
     */
    std::string getName() const;

    /**
     * @brief Set the kitchen where the chef works.
     * @param kitchen Pointer to the kitchen where the chef works.
     */
    void setKitchen(Kitchen* kitchen);

    /**
     * @brief Get the kitchen where the chef works.
     * @return Pointer to the kitchen where the chef works.
     */
    Kitchen* getKitchen() const;
};

#endif
