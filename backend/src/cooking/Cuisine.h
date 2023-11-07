#ifndef Cuisine_H
#define Cuisine_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Meal.h"

/**
 * @brief The Cuisine class represents a type of Meal that is a specific cuisine.
 * 
 * This class inherits from the Meal class and adds additional functionality specific to a cuisine.
 */
class Cuisine : public Meal {

    public:
        /**
         * @brief Constructs a new Cuisine object with the given price, name, chef, and ingredients.
         * 
         * @param price The price of the cuisine.
         * @param name The name of the cuisine.
         * @param chef The name of the chef who created the cuisine.
         * @param ingredients A map of the ingredients used in the cuisine and their quantities.
         */
        Cuisine(double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients);

        /**
         * @brief Constructs a new Cuisine object that is a copy of the given Cuisine object.
         * 
         * @param other The Cuisine object to copy.
         */
        Cuisine(const Cuisine& other);

        /**
         * @brief Destroys the Cuisine object.
         * 
         * This destructor is virtual to ensure that the correct destructor is called when deleting a derived object through a pointer to a base object.
         */
        virtual ~Cuisine();
        
};

#endif