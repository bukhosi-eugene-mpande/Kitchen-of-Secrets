#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <string>
#include <vector>
#include <map>  
#include <unordered_map>

/**
 * @brief The Menu class represents a menu containing a list of menu items.
 */
class Menu{
    private:
        std::unordered_map<int, std::string> menuItems;
        
        
    public:
        /**
         * @brief Constructs a new Menu object.
         * 
         * @param menuItems A map of menu item IDs to their corresponding names.
         */
        Menu(std::unordered_map<int, std::string> menuItems);

        /**
         * @brief Destroys the Menu object.
         */
        ~Menu();

        /**
         * @brief Constructs a new Menu object as a copy of another Menu object.
         * 
         * @param other The Menu object to copy.
         */
        Menu(const Menu& other);

        /**
         * @brief Returns the map of menu items.
         * 
         * @return The map of menu items.
         */
        std::unordered_map<int, std::string> getMenuItems();

        /**
         * @brief Sets the map of menu items.
         * 
         * @param menuItems The new map of menu items.
         */
        void setMenuItems(std::unordered_map<int, std::string> menuItems);
};
#endif