#ifndef ABSTRACT_ORDER_H
#define ABSTRACT_ORDER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

class MenuItem;

class AbstractOrder{
    protected:
        std::unordered_map<std::string,int> ingredients; 

        double price; 

        std::vector<std::shared_ptr<MenuItem>> meals;
    public:
        AbstractOrder();

        virtual ~AbstractOrder();

        virtual double calculatePrice() = 0;

        virtual std::unordered_map<std::string,int> calculateIngredients() = 0;

        std::unordered_map<std::string,int> getIngredients() const;

        double getPrice() const;

        bool IsFinished();
};

#endif