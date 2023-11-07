#ifndef FOOD_H
#define FOOD_H

#include "MenuItem.h"
#include "AbstractOrder.h"

/**
 * @brief The Food class represents a food item in the menu.
 * 
 * This class inherits from MenuItem and AbstractOrder.
 * It contains information about the price, name, and ingredients of the food item.
 */
class Food : public MenuItem , AbstractOrder {
    public:
        /**
         * @brief Construct a new Food object.
         * 
         * @param price The price of the food item.
         * @param name The name of the food item.
         * @param ingredients A map of the ingredients and their quantities in the food item.
         */
        Food(double price,std::string name, std::unordered_map<std::string,int> ingredients);

        /**
         * @brief Destroy the Food object.
         * 
         */
        ~Food();

        /**
         * @brief Construct a new Food object as a copy of another Food object.
         * 
         * @param other The Food object to be copied.
         */
        Food(const Food& other);

        /**
         * @brief Calculate the price of the food item.
         * 
         * @return The price of the food item.
         */
        double calculatePrice();

        /**
         * @brief Calculate the ingredients and their quantities in the food item.
         * 
         * @return A map of the ingredients and their quantities in the food item.
         */
        std::unordered_map<std::string,int> calculateIngredients();

        /**
         * @brief Create a shared pointer to a copy of the Food object.
         * 
         * @return A shared pointer to a copy of the Food object.
         */
        std::shared_ptr<MenuItem> clone() override;
};

#endif