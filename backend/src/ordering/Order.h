#ifndef ORDER_H
#define ORDER_H

#include "AbstractOrder.h"
class Waiter;

class Order : public AbstractOrder {
    private:
        int tableNumber;
        std::shared_ptr<Waiter> waiter;
        bool isCancelled;
    public:
        Order(std::shared_ptr<Engine> engine, int tableNumber, std::vector<std::shared_ptr<MenuItem>> meals, std::shared_ptr<Waiter> waiter);
        Order(const Order& other);
        ~Order();
        double calculatePrice();
        std::unordered_map<std::string,int> calculateIngredients();
        std::shared_ptr<Waiter> getWaiter() const;
        int getTableNumber() const;
        bool getIsCancelled() const;
        void setIsCancelled(bool isCancelled);
        void setWaiter(std::shared_ptr<Waiter> waiter);
        void setTableNumber(int tableNumber);
        void addMeal(std::shared_ptr<MenuItem> meal);
        bool removeMeal(std::shared_ptr<MenuItem> meal);
        std::shared_ptr<MenuItem> getMeal(std::string name);
        std::vector<std::shared_ptr<MenuItem>> getMeals() const;
};

#endif