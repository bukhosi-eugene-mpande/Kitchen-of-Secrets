#ifndef Drink_H
#define Drink_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Meal.h"

class Drink : public Meal {

    public:
        Drink(bool isAlcoholic,double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients);

        Drink(const Drink& other);

        ~Drink();

};

#endif