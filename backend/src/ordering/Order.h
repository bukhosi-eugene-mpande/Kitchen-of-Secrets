#ifndef Order_H
#define Order_H

#include "AbstractOrder.h"
class Waiter;
class Table;

class Order : public AbstractOrder {
    private:
        std::shared_ptr<Table>  table;
        Waiter* waiter;
        bool isCancelled;

    public:

        Order(std::shared_ptr<Table> table, std::vector<std::shared_ptr<MenuItem>> meals, Waiter* waiter);

        Order(const Order& other);

        ~Order();

        double calculatePrice();

        std::unordered_map<std::string,int> calculateIngredients();

        Waiter* getWaiter() const;

        std::shared_ptr<Table> getTable() const;

        bool getIsCancelled() const;

        void setIsCancelled(bool isCancelled);

        void setWaiter(Waiter* waiter);

        void setTable(std::shared_ptr<Table> table);

        void addMeal(std::shared_ptr<MenuItem> meal);

        bool removeMeal(std::shared_ptr<MenuItem> meal);

        std::shared_ptr<MenuItem> getMeal(std::string name);

        std::vector<std::shared_ptr<MenuItem>> getMeals() const;

};

#endif