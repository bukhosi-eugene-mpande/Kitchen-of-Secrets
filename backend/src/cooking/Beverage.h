#ifndef Beverage_H
#define Beverage_H

#include "MenuItem.h"

/**
 * @brief The Beverage class represents a Beverage item in a restaurant.
 * 
 * This class contains information about the name of the Beverage item, the ingredients needed to make it,
 * and methods for calculating the price and ingredients needed to make the Beverage item.
 */

class Beverage : public MenuItem {
        bool isAlcoholic;
    public:
        Beverage(bool isAlcoholic,double price,std::string name, std::unordered_map<std::string,int> ingredients);
        ~Beverage();
        Beverage(const Beverage& other);
        double calculatePrice();
        std::unordered_map<std::string,int> calculateIngredients();
        std::shared_ptr<MenuItem> clone();
        void prepare();
};

#endif