#ifndef FOOD_H
#define FOOD_H

#include "MenuItem.h"
#include "AbstractOrder.h"

class Food : public MenuItem , AbstractOrder {
    public:
        Food(std::shared_ptr<Engine> engine, double price,std::string name, std::unordered_map<std::string,int> ingredients);
        ~Food();
        Food(const Food& other);
        double calculatePrice();
        std::unordered_map<std::string,int> calculateIngredients();
        std::shared_ptr<MenuItem> clone() override;
};

#endif