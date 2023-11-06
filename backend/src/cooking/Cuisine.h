/**
 * @file Cuisine.h
 * @brief Contains the declaration of the Cuisine class, derived from the Meal class.
 */

#ifndef CUISINE_H
#define CUISINE_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Meal.h"

/**
 * @class Cuisine
 * @brief Represents a type of meal prepared by a chef.
 *
 * The Cuisine class is derived from the Meal class and includes information about
 * its price, name, chef, and a list of ingredients used in preparation.
 */
class Cuisine : public Meal {
public:
    /**
     * @brief Constructor for the Cuisine class.
     * @param price The price of the cuisine.
     * @param name The name of the cuisine.
     * @param chef The chef who prepares the cuisine.
     * @param ingredients A list of ingredients used in preparation.
     */
    Cuisine(double price, std::string name, std::string chef, std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Copy constructor for the Cuisine class.
     * @param other Another instance of the Cuisine class to copy from.
     */
    Cuisine(const Cuisine& other);

    /**
     * @brief Destructor for the Cuisine class.
     */
    ~Cuisine();
};

#endif
