/**
 * @file Menu.h
 * @brief Contains the declaration of the Menu class.
 */

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

/**
 * @class Menu
 * @brief Represents a menu containing items and their numbers.
 *
 * The Menu class stores a collection of menu items, each associated with a unique number. It allows for retrieval and management of menu items.
 */
class Menu {
private:
    std::unordered_map<int, std::string> menuItems; /**< An unordered map representing menu items and their corresponding numbers. */

public:
    /**
     * @brief Constructor for the Menu class.
     * @param menuItems An unordered map containing menu items and their corresponding numbers.
     */
    Menu(std::unordered_map<int, std::string> menuItems);

    /**
     * @brief Destructor for the Menu class.
     */
    ~Menu();

    /**
     * @brief Copy constructor for the Menu class.
     * @param other The Menu object to be copied.
     */
    Menu(const Menu& other);

    /**
     * @brief Get the menu items.
     * @return An unordered map of menu items and their corresponding numbers.
     */
    std::unordered_map<int, std::string> getMenuItems();

    /**
     * @brief Set the menu items.
     * @param menuItems An unordered map containing menu items and their corresponding numbers.
     */
    void setMenuItems(std::unordered_map<int, std::string> menuItems);
};

#endif
