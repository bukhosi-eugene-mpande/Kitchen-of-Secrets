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
class Cuisine;
class Drink;

class Kitchen : public GameComponent {
    private:
<<<<<<< HEAD:backend/src/cooking/Kitchen.h
        std::unordered_map<std::string,std::shared_ptr<Meal>> availableMeals;
        std::shared_ptr<HeadChef> headChef;
        std::shared_ptr<DeputyHeadChef> deputyHeadChef;
        std::vector<std::shared_ptr<Order>> preparedOrders;
        std::vector<std::shared_ptr<Order>> canceledOrders; 
        int numMeals;
        std::shared_ptr<Management> management;
    public:
        Kitchen(std::shared_ptr<Engine> engine, std::shared_ptr<Management> management, std::vector<std::shared_ptr<Meal>> meals);
=======
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

>>>>>>> kitchen-Intergration:backend/src/sudo_cooking/Kitchen.h
        Kitchen(const Kitchen& other);
        ~Kitchen();
        std::string getName() const;
        void addMeal(std::shared_ptr<Meal> meal);
        void addOrder(std::shared_ptr<Order> order);
        void removeMeal(std::string name);
<<<<<<< HEAD:backend/src/cooking/Kitchen.h
        std::shared_ptr<Order> getPreparedOrder(std::shared_ptr<Waiter> waiter);
        std::shared_ptr<Order> getCanceledOrder(std::shared_ptr<Waiter> waiter);
=======

        std::shared_ptr<Order> getPreparedOrder(Waiter* waiter);

        std::shared_ptr<Order> getCanceledOrder(Waiter* waiter);

>>>>>>> kitchen-Intergration:backend/src/sudo_cooking/Kitchen.h
        std::unordered_map<std::string,int> getIngredients(std::string name);
        std::string getChefName(std::string Meal);
        double getPrice(std::string name);
        std::unordered_map<int,std::string> getMenu();
<<<<<<< HEAD:backend/src/cooking/Kitchen.h
        std::shared_ptr<Management> getManagement() const;
=======

        std::unordered_map<int,std::string> getDrinksMenu();

        std::shared_ptr<Drink> getDrink(std::string name);

        std::shared_ptr<Cuisine> getCusine(std::string name);

        std::unordered_map<int,std::string> getCuisineMenu();

        Management* getManagement() const;

>>>>>>> kitchen-Intergration:backend/src/sudo_cooking/Kitchen.h
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
<<<<<<< HEAD:backend/src/cooking/Kitchen.h
        virtual void sendEvent();
        virtual void receiveEvent(std::string event);
=======

        void generateCusines();

        void generateDrinks();        
>>>>>>> kitchen-Intergration:backend/src/sudo_cooking/Kitchen.h
};

#endif