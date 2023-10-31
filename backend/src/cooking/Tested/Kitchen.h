#ifndef Kitchen_H
#define Kitchen_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class Order;
class Meal;
class DeputyHeadChef;
class HeadChef;
class Waiter;
class Management;

class Kitchen {
    private:
    std::unordered_map<std::string,std::shared_ptr<Meal>> AvailableMeals;
    std::shared_ptr<HeadChef> headChef;
    std::shared_ptr<DeputyHeadChef> deputyHeadChef;
    std::vector<std::shared_ptr<Order>> preparedOrders;
    std::vector<std::shared_ptr<Order>> canceledOrders; 
    int numMeals;
    Management* management;

    public:

        Kitchen(Management* management,std::vector<std::shared_ptr<Meal>> meals);

        Kitchen(const Kitchen& other);

        ~Kitchen();

        std::string getName() const;

        void addMeal(std::shared_ptr<Meal> meal);

        void addOrder(std::shared_ptr<Order> order);

        void removeMeal(std::string name);

        std::shared_ptr<Order> getPreparedOrder(std::shared_ptr<Waiter> waiter);

        std::shared_ptr<Order> getCanceledOrder(std::shared_ptr<Waiter> waiter);

        std::unordered_map<std::string,int> getIngredients(std::string name);

        double getPrice(std::string name);

        std::unordered_map<int,std::string> getMenu();

        Management* getManagement() const;

        void cancelOrder(std::shared_ptr<Order> order);

        void finishOrder(std::shared_ptr<Order> order);

        void notifyWaiterOfPreparedOrder(std::shared_ptr<Order> order);

        void notifyWaiterOfCanceledOrder(std::shared_ptr<Order> order);

        std::unordered_map<std::string,std::shared_ptr<Meal>> getAvailableMeals() const;

        std::shared_ptr<HeadChef> getHeadChef() const;

        std::shared_ptr<DeputyHeadChef> getDeputyHeadChef() const;

        std::shared_ptr<Kitchen> shared_from_this();

        void createHeadChef();

        void createDeputyHeadChef();

};

#endif