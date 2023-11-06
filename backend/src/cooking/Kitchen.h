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
class PlayerInteraction;
class Cuisine;
class Drink;

class Kitchen{ 
    private:
    //used for interaction out side the kitchen subsystem
    PlayerInteraction* management;

    //in charge of doing rounds 
    std::shared_ptr<HeadChef> headChef;

    //in charge of starting the prepartion of the meal
    std::shared_ptr<DeputyHeadChef> deputyHeadChef;

    std::unordered_map<std::string,std::shared_ptr<Meal>> AvailableMeals;
    std::unordered_map<std::string,std::shared_ptr<Cuisine>> cuisines;
    std::unordered_map<std::string,std::shared_ptr<Drink>> drinks;
    
    std::vector<std::shared_ptr<Order>> preparedOrders;
    std::vector<std::shared_ptr<Order>> canceledOrders;

    int numMeals;

    public:

        Kitchen(PlayerInteraction* management);

        Kitchen(const Kitchen& other);

        ~Kitchen();

        std::string getName() const;

        void addMeal(std::shared_ptr<Meal> meal);

        void addOrder(std::shared_ptr<Order> order);

        void removeMeal(std::string name);

        std::shared_ptr<Order> getPreparedOrder(Waiter* waiter);

        std::shared_ptr<Order> getCanceledOrder(Waiter* waiter);

        std::unordered_map<std::string,int> getIngredients(std::string name);

        std::string getChefName(std::string Meal);

        double getPrice(std::string name);

        std::unordered_map<int,std::string> getMenu();

        std::unordered_map<int,std::string> getDrinksMenu();

        std::shared_ptr<Drink> getDrink(std::string name);

        std::shared_ptr<Cuisine> getCusine(std::string name);

        std::unordered_map<int,std::string> getCuisineMenu();

        PlayerInteraction* getManagement() const;

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