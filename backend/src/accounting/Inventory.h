/**
 * @file Inventory.h
 * @brief Contains the declaration of the Inventory class.
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

/**
 * @class Inventory
 * @brief Represents an inventory of ingredients and their quantities.
 */
class Inventory {
private:
    std::unordered_map<std::string, int> inventory;

public:
    /**
     * @brief Constructor for the Inventory class.
     */
    Inventory();

    /**
     * @brief Copy constructor for the Inventory class.
     * @param other The Inventory object to be copied.
     */
    Inventory(const Inventory& other);

    /**
     * @brief Destructor for the Inventory class.
     */
    ~Inventory();

    /**
     * @brief Request a specified quantity of ingredients from the inventory.
     * @param ingredients A map of ingredient names and the requested quantities.
     * @return `true` if the requested ingredients are available in sufficient quantities; otherwise, `false`.
     */
    bool requestIngredients(std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Get the current state of the inventory.
     * @return A map of ingredient names and their current quantities.
     */
    std::unordered_map<std::string, int> getInventory() const;
};

#endif
