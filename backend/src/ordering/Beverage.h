/**
 * @file Beverage.h
 * @brief Contains the declaration of the Beverage class.
 */

#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "MenuItem.h"
#include "AbstractOrder.h"

/**
 * @class Beverage
 * @brief Represents a beverage menu item and an abstract order of beverages.
 *
 * The Beverage class inherits from both MenuItem and AbstractOrder, allowing it to be part of the menu and represent an abstract order of beverages. It includes information about whether the beverage is alcoholic, its price, name, and ingredients.
 */
class Beverage : public MenuItem, public AbstractOrder {
    bool isAlcoholic; ///< Indicates whether the beverage is alcoholic.

public:
    /**
     * @brief Constructor for the Beverage class.
     * @param isAlcoholic True if the beverage is alcoholic, false otherwise.
     * @param price The price of the beverage.
     * @param name The name of the beverage.
     * @param ingredients An unordered map of ingredients and their quantities.
     */
    Beverage(bool isAlcoholic, double price, std::string name, std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Destructor for the Beverage class.
     */
    ~Beverage();

    /**
     * @brief Copy constructor for the Beverage class.
     * @param other The Beverage object to be copied.
     */
    Beverage(const Beverage& other);

    /**
     * @brief Calculate the total price of the beverage order.
     * @return The calculated price of the beverage order.
     */
    double calculatePrice() override;

    /**
     * @brief Calculate the ingredients in the beverage order.
     * @return An unordered map of ingredients and their quantities in the beverage order.
     */
    std::unordered_map<std::string, int> calculateIngredients() override;

    /**
     * @brief Create a deep copy of the Beverage object.
     * @return A shared pointer to a new Beverage object that is a copy of the original.
     */
    std::shared_ptr<MenuItem> clone() override;

    /**
     * @brief Check if the beverage is alcoholic.
     * @return True if the beverage is alcoholic, false otherwise.
     */
    bool getIsAlcoholic() const;
};

#endif
