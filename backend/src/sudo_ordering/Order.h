#ifndef ORDER_H
#define ORDER_H

#include "AbstractOrder.h"
class Waiter;
class Table;

class Order : public AbstractOrder {
    private:
        std::shared_ptr<Table>  table;
        Waiter* waiter;
        bool isCancelled;
    public:
<<<<<<< HEAD:backend/src/ordering/Order.h
        Order(std::shared_ptr<Engine> engine, int tableNumber, std::vector<std::shared_ptr<MenuItem>> meals, std::shared_ptr<Waiter> waiter);
=======

        Order(std::shared_ptr<Table> table, std::vector<std::shared_ptr<MenuItem>> meals, Waiter* waiter);

>>>>>>> kitchen-Intergration:backend/src/sudo_ordering/Order.h
        Order(const Order& other);
        ~Order();
        double calculatePrice();
        std::unordered_map<std::string,int> calculateIngredients();
<<<<<<< HEAD:backend/src/ordering/Order.h
        std::shared_ptr<Waiter> getWaiter() const;
        int getTableNumber() const;
=======

        Waiter* getWaiter() const;

        std::shared_ptr<Table> getTable() const;

>>>>>>> kitchen-Intergration:backend/src/sudo_ordering/Order.h
        bool getIsCancelled() const;
        void setIsCancelled(bool isCancelled);
<<<<<<< HEAD:backend/src/ordering/Order.h
        void setWaiter(std::shared_ptr<Waiter> waiter);
        void setTableNumber(int tableNumber);
=======

        void setWaiter(Waiter* waiter);

        void setTable(std::shared_ptr<Table> table);

>>>>>>> kitchen-Intergration:backend/src/sudo_ordering/Order.h
        void addMeal(std::shared_ptr<MenuItem> meal);
        bool removeMeal(std::shared_ptr<MenuItem> meal);
        std::shared_ptr<MenuItem> getMeal(std::string name);
        std::vector<std::shared_ptr<MenuItem>> getMeals() const;
};

#endif