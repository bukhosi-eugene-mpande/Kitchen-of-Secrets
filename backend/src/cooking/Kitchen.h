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
class Cuisine;
class Drink;

class Kitchen {
    private:
    std::unordered_map<std::string,std::shared_ptr<Meal>> AvailableMeals;
    std::unordered_map<std::string,std::shared_ptr<Cuisine>> cuisines;
    std::unordered_map<std::string,std::shared_ptr<Drink>> drinks;
    std::shared_ptr<HeadChef> headChef;
    std::shared_ptr<DeputyHeadChef> deputyHeadChef;
    std::vector<std::shared_ptr<Order>> preparedOrders;
    std::vector<std::shared_ptr<Order>> canceledOrders; 
    int numMeals;
    Management* management;

    public:

        Kitchen(Management* management);

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

        std::unordered_map<int,std::string> getDrinksMenu();

        std::unordered_map<int,std::string> getCuisineMenu();

        Management* getManagement() const;

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

        void generateCusines();

        void generateDrinks();
        
};

#endif