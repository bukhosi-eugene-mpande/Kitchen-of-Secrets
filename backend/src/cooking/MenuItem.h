#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <unordered_map>
#include <string>
#include <memory>

#include "GameComponent.h"

class MenuItem : public GameComponent {
    protected:
        std::unordered_map<std::string, int> mealIngredients; 
        std::string name; 
        double mealPrice; 
        bool isPrepared; 
    public:
        MenuItem(std::shared_ptr<Engine> engine, double price, std::string name, std::unordered_map<std::string, int> ingredients);
        MenuItem(const MenuItem& other);
        virtual ~MenuItem();
        virtual std::shared_ptr<MenuItem> clone() = 0;
        void prepare();
        std::string getName() const;
        std::unordered_map<std::string,int> getMealIngredients() const;
        double getMealPrice() const;
        bool getIsPrepared() const;
};

#endif

