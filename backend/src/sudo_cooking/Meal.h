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

    protected: 
        bool isAlcoholic; 

    public:
        Meal(double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients);

        Meal(const Meal& other);

        ~Meal();

        void setName(std::string name);

        std::string getName() const;

        std::string getChef() const;

        void setChef(std::string chef);

        std::unordered_map<std::string,int> getIngredients() const;

        void setIngredients(std::unordered_map<std::string,int> ingredients);

        double getPrice() const;

        void setPrice(double price);

        bool getIsAlcoholic() const;

};

#endif
