#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "MenuItem.h"
#include "AbstractOrder.h"

class Beverage : public MenuItem, AbstractOrder{
        bool isAlcoholic;
    public:
        Beverage(bool isAlcoholic,double price,std::string name, std::unordered_map<std::string,int> ingredients);
        ~Beverage();
        Beverage(const Beverage& other);
        double calculatePrice();
        std::unordered_map<std::string,int> calculateIngredients();
        std::shared_ptr<MenuItem> clone() override;
        bool getIsAlcoholic() const;
};

#endif