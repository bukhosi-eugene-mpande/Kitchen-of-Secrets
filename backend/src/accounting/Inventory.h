#ifndef INVENTORY_H
#define INVENTORY_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

/**
 * @brief The Inventory class represents a collection of ingredients and their quantities.
 */
class Inventory {
    private:
        std::unordered_map<std::string, int> inventory; /**< The map of ingredients and their quantities. */
        
    public:
        /**
         * @brief Constructs an empty Inventory object.
         */
        Inventory();

        /**
         * @brief Constructs an Inventory object as a copy of another Inventory object.
         * @param other The Inventory object to copy.
         */
        Inventory(const Inventory& other);

        /**
         * @brief Destroys the Inventory object.
         */
        ~Inventory();

        /**
         * @brief Attempts to remove the specified ingredients from the inventory.
         * @param ingredients The map of ingredients and their requested quantities.
         * @return True if the ingredients were successfully removed, false otherwise.
         */
        bool requestIngredients(std::unordered_map<std::string,int> ingredients);

        /**
         * @brief Returns a copy of the current inventory.
         * @return A map of ingredients and their quantities.
         */
        std::unordered_map<std::string,int> getInventory() const;
};

#endif