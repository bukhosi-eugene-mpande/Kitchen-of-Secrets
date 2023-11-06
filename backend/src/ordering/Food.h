/**
 * @file Food.h
 * @brief Contains the declaration of the Food class.
 */

#ifndef FOOD_H
#define FOOD_H

#include "MenuItem.h"
#include "AbstractOrder.h"

/**
 * @class Food
 * @brief Represents a food menu item and an abstract order of food.
 *
 * The Food class inherits from both MenuItem and AbstractOrder, allowing it to be part of the menu and represent an abstract order of food items. It includes information such as the price, name, and ingredients of the food item.
 */
class Food : public MenuItem, public AbstractOrder {
public:
    /**
     * @brief Constructor for the Food class.
     * @param price The price of the food item.
     * @param name The name of the food item.
     * @param ingredients An unordered map of ingredients and their quantities.
     */
    Food(double price, std::string name, std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Destructor for the Food class.
     */
    ~Food();

    /**
     * @brief Copy constructor for the Food class.
     * @param other The Food object to be copied.
     */
    Food(const Food& other);

    /**
     * @brief Calculate the total price of the food order.
     * @return The calculated price of the food order.
     */
    double calculatePrice() override;

    /**
     * @brief Calculate the ingredients in the food order.
     * @return An unordered map of ingredients and their quantities in the food order.
     */
    std::unordered_map<std::string, int> calculateIngredients() override;

    /**
     * @brief Create a deep copy of the Food object.
     * @return A shared pointer to a new Food object that is a copy of the original.
     */
    std::shared_ptr<MenuItem> clone() override;
};

#endif
