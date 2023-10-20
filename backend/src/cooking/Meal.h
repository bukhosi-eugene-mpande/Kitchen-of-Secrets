#ifndef Meal_H
#define Meal_H

#include <unordered_map>
#include <string>
#include <memory>

class Meal {
    private:
    std::unordered_map<std::string,int> ingredients;
    std::string name;
    std::string chef; 
    double price; 

    public:

        Meal(double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients);

        Meal(const Meal& other);

        ~Meal();

        std::string getName() const;

        std::string getChef() const;

        std::unordered_map<std::string,int> getIngredients() const;

        double getPrice() const;

};

#endif
