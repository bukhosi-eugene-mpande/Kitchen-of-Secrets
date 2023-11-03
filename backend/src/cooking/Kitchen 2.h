#ifndef KITCHEN_H
#define KITCHEN_H

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

class Kitchen : public GameComponent {
    private:
        std::unordered_map<std::string,std::shared_ptr<Meal>> availableMeals;
        std::shared_ptr<HeadChef> headChef;
        std::shared_ptr<DeputyHeadChef> deputyHeadChef;
        std::vector<std::shared_ptr<Order>> preparedOrders;
        std::vector<std::shared_ptr<Order>> canceledOrders; 
        int numMeals;
        std::shared_ptr<Management> management;
    public:
        Kitchen(std::shared_ptr<Engine> engine, std::shared_ptr<Management> management, std::vector<std::shared_ptr<Meal>> meals);
        Kitchen(const Kitchen& other);
        ~Kitchen();
        std::string getName() const;
        void addMeal(std::shared_ptr<Meal> meal);
        void addOrder(std::shared_ptr<Order> order);
        void removeMeal(std::string name);
        std::shared_ptr<Order> getPreparedOrder(std::shared_ptr<Waiter> waiter);
        std::shared_ptr<Order> getCanceledOrder(std::shared_ptr<Waiter> waiter);
        std::unordered_map<std::string,int> getIngredients(std::string name);
        std::string getChefName(std::string Meal);
        double getPrice(std::string name);
        std::unordered_map<int,std::string> getMenu();
        std::shared_ptr<Management> getManagement() const;
        void cancelOrder(std::shared_ptr<Order> order);
        void finishOrder(std::shared_ptr<Order> order);
        void notifyWaiterOfPreparedOrder(std::shared_ptr<Order> order);
        void notifyWaiterOfCanceledOrder(std::shared_ptr<Order> order);
        std::unordered_map<std::string,std::shared_ptr<Meal>> getAvailableMeals() const;
        std::shared_ptr<HeadChef> getHeadChef() const;
        std::shared_ptr<DeputyHeadChef> getDeputyHeadChef() const;
        std::vector<std::string> generateListOfResposibilties(std::string chefName);
        void createHeadChef();
        void createDeputyHeadChef();
        std::vector<std::shared_ptr<Order>> getPreparedOrders() const;
        std::vector<std::shared_ptr<Order>> getCanceledOrders() const;
        virtual void sendEvent();
        virtual void receiveEvent(std::string event);
};

#endif