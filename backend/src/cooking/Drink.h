#ifndef Drink_H
#define Drink_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Meal.h"

/**
 * @brief The Drink class represents a type of Meal that is a drink.
 * 
 * This class inherits from the Meal class and adds the ability to specify whether the drink is alcoholic or not.
 * 
 */
class Drink : public Meal {

    public:
        /**
         * @brief Construct a new Drink object
         * 
         * @param isAlcoholic A boolean value indicating whether the drink is alcoholic or not.
         * @param price The price of the drink.
         * @param name The name of the drink.
         * @param chef The name of the chef who created the drink.
         * @param ingredients A map of ingredients and their quantities required to make the drink.
         */
        Drink(bool isAlcoholic,double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients);

        /**
         * @brief Construct a new Drink object by copying another Drink object.
         * 
         * @param other The Drink object to copy.
         */
        Drink(const Drink& other);

        /**
         * @brief Destroy the Drink object
         * 
         */
        ~Drink();

};

#endif