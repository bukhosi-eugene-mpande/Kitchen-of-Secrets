/**
 * @file Drink.h
 * @brief Contains the declaration of the Drink class, derived from the Meal class.
 */

#ifndef DRINK_H
#define DRINK_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Meal.h"

/**
 * @class Drink
 * @brief Represents a drink item, derived from the Meal class.
 *
 * The Drink class is derived from the Meal class and represents a drink item on the menu. It provides
 * information about the drink's characteristics, price, chef, and required ingredients.
 */
class Drink : public Meal {
public:
    /**
     * @brief Constructor for the Drink class.
     * @param isAlcoholic A boolean indicating whether the drink is alcoholic.
     * @param price The price of the drink.
     * @param name The name of the drink.
     * @param chef The chef responsible for preparing the drink.
     * @param ingredients A map of required ingredients and their quantities.
     */
    Drink(bool isAlcoholic, double price, std::string name, std::string chef, std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Copy constructor for the Drink class.
     * @param other Another Drink object to copy from.
     */
    Drink(const Drink& other);

    /**
     * @brief Destructor for the Drink class.
     */
    ~Drink();
};

#endif
