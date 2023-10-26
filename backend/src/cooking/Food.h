#ifndef Food_H
#define Food_H

#include "MenuItem.h"
#include "AbstractOrder.h"

/**
 * @brief The Food class represents a food item in a restaurant.
 * 
 * This class contains information about the name of the food item, the ingredients needed to make it,
 * and methods for calculating the price and ingredients needed to make the food item.
 */

class Food : public MenuItem , AbstractOrder{

    public:
        Food(double price,std::string name, std::unordered_map<std::string,int> ingredients);
        ~Food();
        Food(const Food& other);
        double calculatePrice();
        std::unordered_map<std::string,int> calculateIngredients();
        std::shared_ptr<MenuItem> clone();
};

#endif