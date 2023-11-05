#ifndef Cuisine_H
#define Cuisine_H

#include <unordered_map>
#include <string>
#include <memory>
#include "Meal.h"

class Cuisine : public Meal {

    public:
        Cuisine(double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients);

        Cuisine(const Cuisine& other);

        ~Cuisine();
        
};

#endif