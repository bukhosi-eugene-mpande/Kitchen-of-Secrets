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

/**
 * @brief The Kitchen class represents a subsystem that is responsible for preparing meals and drinks.
 * 
 */
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

        /**
         * @brief Construct a new Kitchen object
         * 
         * @param management A pointer to the PlayerInteraction object that will be used for interaction outside the kitchen subsystem.
         */
        Kitchen(PlayerInteraction* management);

        /**
         * @brief Construct a new Kitchen object by copying another Kitchen object.
         * 
         * @param other The Kitchen object to be copied.
         */
        Kitchen(const Kitchen& other);

        /**
         * @brief Destroy the Kitchen object
         * 
         */
        ~Kitchen();

        /**
         * @brief Get the name of the Kitchen object.
         * 
         * @return std::string The name of the Kitchen object.
         */
        std::string getName() const;

        /**
         * @brief Add a new Meal object to the Kitchen object.
         * 
         * @param meal A shared pointer to the Meal object to be added.
         */
        void addMeal(std::shared_ptr<Meal> meal);

        /**
         * @brief Add a new Order object to the Kitchen object.
         * 
         * @param order A shared pointer to the Order object to be added.
         */
        void addOrder(std::shared_ptr<Order> order);

        /**
         * @brief Remove a Meal object from the Kitchen object.
         * 
         * @param name The name of the Meal object to be removed.
         */
        void removeMeal(std::string name);

        /**
         * @brief Get a prepared Order object from the Kitchen object.
         * 
         * @param waiter A pointer to the Waiter object that will receive the prepared Order object.
         * @return std::shared_ptr<Order> A shared pointer to the prepared Order object.
         */
        std::shared_ptr<Order> getPreparedOrder(Waiter* waiter);

        /**
         * @brief Get a canceled Order object from the Kitchen object.
         * 
         * @param waiter A pointer to the Waiter object that will receive the canceled Order object.
         * @return std::shared_ptr<Order> A shared pointer to the canceled Order object.
         */
        std::shared_ptr<Order> getCanceledOrder(Waiter* waiter);

        /**
         * @brief Get the ingredients of a Meal object.
         * 
         * @param name The name of the Meal object.
         * @return std::unordered_map<std::string,int> An unordered map that maps the name of an ingredient to its quantity.
         */
        std::unordered_map<std::string,int> getIngredients(std::string name);

        /**
         * @brief Get the name of the Chef object that is responsible for preparing a Meal object.
         * 
         * @param Meal The name of the Meal object.
         * @return std::string The name of the Chef object.
         */
        std::string getChefName(std::string Meal);

        /**
         * @brief Get the price of a Meal object.
         * 
         * @param name The name of the Meal object.
         * @return double The price of the Meal object.
         */
        double getPrice(std::string name);

        /**
         * @brief Get the menu of the Kitchen object.
         * 
         * @return std::unordered_map<int,std::string> An unordered map that maps the ID of a Meal object to its name.
         */
        std::unordered_map<int,std::string> getMenu();

        /**
         * @brief Get the drinks menu of the Kitchen object.
         * 
         * @return std::unordered_map<int,std::string> An unordered map that maps the ID of a Drink object to its name.
         */
        std::unordered_map<int,std::string> getDrinksMenu();

        /**
         * @brief Get a Drink object from the Kitchen object.
         * 
         * @param name The name of the Drink object.
         * @return std::shared_ptr<Drink> A shared pointer to the Drink object.
         */
        std::shared_ptr<Drink> getDrink(std::string name);

        /**
         * @brief Get a Cuisine object from the Kitchen object.
         * 
         * @param name The name of the Cuisine object.
         * @return std::shared_ptr<Cuisine> A shared pointer to the Cuisine object.
         */
        std::shared_ptr<Cuisine> getCusine(std::string name);

        /**
         * @brief Get the cuisine menu of the Kitchen object.
         * 
         * @return std::unordered_map<int,std::string> An unordered map that maps the ID of a Cuisine object to its name.
         */
        std::unordered_map<int,std::string> getCuisineMenu();

        /**
         * @brief Get the PlayerInteraction object that is used for interaction outside the kitchen subsystem.
         * 
         * @return PlayerInteraction* A pointer to the PlayerInteraction object.
         */
        PlayerInteraction* getManagement() const;

        /**
         * @brief Cancel an Order object.
         * 
         * @param order A shared pointer to the Order object to be canceled.
         */
        void cancelOrder(std::shared_ptr<Order> order);

        /**
         * @brief Finish an Order object.
         * 
         * @param order A shared pointer to the Order object to be finished.
         */
        void finishOrder(std::shared_ptr<Order> order);

        /**
         * @brief Notify a Waiter object of a prepared Order object.
         * 
         * @param order A shared pointer to the prepared Order object.
         */
        void notifyWaiterOfPreparedOrder(std::shared_ptr<Order> order);

        /**
         * @brief Notify a Waiter object of a canceled Order object.
         * 
         * @param order A shared pointer to the canceled Order object.
         */
        void notifyWaiterOfCanceledOrder(std::shared_ptr<Order> order);

        /**
         * @brief Get the AvailableMeals object of the Kitchen object.
         * 
         * @return std::unordered_map<std::string,std::shared_ptr<Meal>> An unordered map that maps the name of a Meal object to a shared pointer to the Meal object.
         */
        std::unordered_map<std::string,std::shared_ptr<Meal>> getAvailableMeals() const;

        /**
         * @brief Get the HeadChef object of the Kitchen object.
         * 
         * @return std::shared_ptr<HeadChef> A shared pointer to the HeadChef object.
         */
        std::shared_ptr<HeadChef> getHeadChef() const;

        /**
         * @brief Get the DeputyHeadChef object of the Kitchen object.
         * 
         * @return std::shared_ptr<DeputyHeadChef> A shared pointer to the DeputyHeadChef object.
         */
        std::shared_ptr<DeputyHeadChef> getDeputyHeadChef() const;

        /**
         * @brief Generate a list of responsibilities for a Chef object.
         * 
         * @param chefName The name of the Chef object.
         * @return std::vector<std::string> A vector of strings that represent the responsibilities of the Chef object.
         */
        std::vector<std::string> generateListOfResposibilties(std::string chefName);

        /**
         * @brief Create a new HeadChef object for the Kitchen object.
         * 
         */
        void createHeadChef();

        /**
         * @brief Create a new DeputyHeadChef object for the Kitchen object.
         * 
         */
        void createDeputyHeadChef();

        /**
         * @brief Get the prepared Orders of the Kitchen object.
         * 
         * @return std::vector<std::shared_ptr<Order>> A vector of shared pointers to the prepared Order objects.
         */
        std::vector<std::shared_ptr<Order>> getPreparedOrders() const;

        /**
         * @brief Get the canceled Orders of the Kitchen object.
         * 
         * @return std::vector<std::shared_ptr<Order>> A vector of shared pointers to the canceled Order objects.
         */
        std::vector<std::shared_ptr<Order>> getCanceledOrders() const;

        /**
         * @brief Generate the Cuisine objects of the Kitchen object.
         * 
         */
        void generateCusines();

        /**
         * @brief Generate the Drink objects of the Kitchen object.
         * 
         */
        void generateDrinks();        
};

#endif