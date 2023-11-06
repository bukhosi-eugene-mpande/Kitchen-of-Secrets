/**
 * @file MenuItem.h
 * @brief Contains the declaration of the MenuItem class.
 */

#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <unordered_map>
#include <string>
#include <memory>

/**
 * @class MenuItem
 * @brief Represents a menu item with its ingredients and attributes.
 *
 * The MenuItem class stores information about a menu item, including its name, ingredients, price, and preparation status.
 */
class MenuItem {
protected:
    std::unordered_map<std::string, int> mealIngredients; /**< An unordered map of ingredients and their quantities in the menu item. */
    std::string name; /**< The name of the menu item. */
    double mealPrice; /**< The price of the menu item. */
    bool isPrepared; /**< A flag indicating whether the menu item is prepared. */

public:
    /**
     * @brief Constructor for the MenuItem class.
     * @param price The price of the menu item.
     * @param name The name of the menu item.
     * @param ingredients An unordered map of ingredients and their quantities in the menu item.
     */
    MenuItem(double price, std::string name, std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Copy constructor for the MenuItem class.
     * @param other The MenuItem object to be copied.
     */
    MenuItem(const MenuItem& other);

    /**
     * @brief Virtual destructor for the MenuItem class.
     */
    virtual ~MenuItem();

    /**
     * @brief Clone function to create a copy of the MenuItem.
     * @return A shared pointer to a new MenuItem object.
     */
    virtual std::shared_ptr<MenuItem> clone() = 0;

    /**
     * @brief Prepare the menu item.
     */
    void prepare();

    /**
     * @brief Get the name of the menu item.
     * @return The name of the menu item.
     */
    std::string getName() const;

    /**
     * @brief Get the ingredients and their quantities in the menu item.
     * @return An unordered map of ingredients and their quantities.
     */
    std::unordered_map<std::string, int> getMealIngredients() const;

    /**
     * @brief Get the price of the menu item.
     * @return The price of the menu item.
     */
    double getMealPrice() const;

    /**
     * @brief Get the preparation status of the menu item.
     * @return A boolean indicating whether the menu item is prepared.
     */
    bool getIsPrepared() const;
};

#endif
