#ifndef Food_H
#define Food_H

#include "MenuItem.h"
#include "AbstractOrder.h"

class Food : public MenuItem , AbstractOrder{

    public:
        Food(double price,std::string name, std::unordered_map<std::string,int> ingredients);
        ~Food();
        Food(const Food& other);
        double calculatePrice();
        std::unordered_map<std::string,int> calculateIngredients();
        std::shared_ptr<MenuItem> clone() override;
};

#endif