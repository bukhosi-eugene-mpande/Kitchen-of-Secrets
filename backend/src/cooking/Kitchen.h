/**
 * @file Kitchen.h
 * @brief Contains the declaration of the Kitchen class.
 */

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
 * @class Kitchen
 * @brief Represents a kitchen subsystem responsible for meal preparation and management.
 *
 * The Kitchen class represents a kitchen subsystem responsible for meal preparation and management.
 * It includes key roles like the HeadChef and DeputyHeadChef, manages meals, orders, and interacts with
 * waiters and management.
 */
class Kitchen {
private:
    PlayerInteraction* management; /**< A pointer to the PlayerInteraction object for management interaction. */

    std::shared_ptr<HeadChef> headChef; /**< A pointer to the HeadChef overseeing kitchen operations. */

    std::shared_ptr<DeputyHeadChef> deputyHeadChef; /**< A pointer to the DeputyHeadChef responsible for meal preparation. */

    std::unordered_map<std::string, std::shared_ptr<Meal>> AvailableMeals; /**< A collection of available meals. */

    std::unordered_map<std::string, std::shared_ptr<Cuisine>> cuisines; /**< A collection of cuisine meals. */

    std::unordered_map<std::string, std::shared_ptr<Drink>> drinks; /**< A collection of drink meals. */

    std::vector<std::shared_ptr<Order>> preparedOrders; /**< A list of prepared orders. */

    std::vector<std::shared_ptr<Order>> canceledOrders; /**< A list of canceled orders. */

    int numMeals; /**< The number of available meals. */

public:
    /**
     * @brief Constructor for the Kitchen class.
     * @param management A pointer to the PlayerInteraction object for management interaction.
     */
    Kitchen(PlayerInteraction* management);

    /**
     * @brief Copy constructor for the Kitchen class.
     * @param other The Kitchen object to copy from.
     */
    Kitchen(const Kitchen& other);

    /**
     * @brief Destructor for the Kitchen class.
     */
    ~Kitchen();

    /**
     * @brief Get the name of the kitchen.
     * @return A string containing the name of the kitchen.
     */
    std::string getName() const;

    /**
     * @brief Add a meal to the kitchen.
     * @param meal A shared pointer to the Meal to be added.
     */
    void addMeal(std::shared_ptr<Meal> meal);

    /**
     * @brief Add an order to the kitchen.
     * @param order A shared pointer to the Order to be added.
     */
    void addOrder(std::shared_ptr<Order> order);

    /**
     * @brief Remove a meal from the kitchen.
     * @param name The name of the meal to be removed.
     */
    void removeMeal(std::string name);

    /**
     * @brief Get a prepared order for a waiter.
     * @param waiter A pointer to the Waiter requesting the prepared order.
     * @return A shared pointer to the prepared order.
     */
    std::shared_ptr<Order> getPreparedOrder(Waiter* waiter);

    /**
     * @brief Get a canceled order for a waiter.
     * @param waiter A pointer to the Waiter requesting the canceled order.
     * @return A shared pointer to the canceled order.
     */
    std::shared_ptr<Order> getCanceledOrder(Waiter* waiter);

    /**
     * @brief Get the ingredients of a meal.
     * @param name The name of the meal.
     * @return An unordered map containing the ingredients and their quantities.
     */
    std::unordered_map<std::string, int> getIngredients(std::string name);

    /**
     * @brief Get the name of the chef for a meal.
     * @param Meal The name of the meal.
     * @return A string containing the chef's name.
     */
    std::string getChefName(std::string Meal);

    /**
     * @brief Get the price of a meal.
     * @param name The name of the meal.
     * @return The price of the meal.
     */
    double getPrice(std::string name);

    /**
     * @brief Get the menu of available meals.
     * @return An unordered map with menu item numbers as keys and meal names as values.
     */
    std::unordered_map<int, std::string> getMenu();

    /**
     * @brief Get the menu of available drinks.
     * @return An unordered map with menu item numbers as keys and drink names as values.
     */
    std::unordered_map<int, std::string> getDrinksMenu();

    /**
     * @brief Get a specific drink by name.
     * @param name The name of the drink.
     * @return A shared pointer to the specified drink.
     */
    std::shared_ptr<Drink> getDrink(std::string name);

    /**
     * @brief Get a specific cuisine meal by name.
     * @param name The name of the cuisine meal.
     * @return A shared pointer to the specified cuisine meal.
     */
    std::shared_ptr<Cuisine> getCusine(std::string name);

    /**
     * @brief Get the menu of available cuisine meals.
     * @return An unordered map with menu item numbers as keys and cuisine meal names as values.
     */
    std::unordered_map<int, std::string> getCuisineMenu();

    /**
     * @brief Get the management interaction object.
     * @return A pointer to the PlayerInteraction object for management interaction.
     */
    PlayerInteraction* getManagement() const;

    /**
     * @brief Cancel an order.
     * @param order A shared pointer to the order to be canceled.
     */
    void cancelOrder(std::shared_ptr<Order> order);

    /**
     * @brief Finish an order.
     * @param order A shared pointer to the order to be finished.
     */
    void finishOrder(std::shared_ptr<Order> order);

    /**
     * @brief Notify the waiter of a prepared order.
     * @param order A shared pointer to the prepared order.
     */
    void notifyWaiterOfPreparedOrder(std::shared_ptr<Order> order);

    /**
     * @brief Notify the waiter of a canceled order.
     * @param order A shared pointer to the canceled order.
     */
    void notifyWaiterOfCanceledOrder(std::shared_ptr<Order> order);

    /**
     * @brief Get the collection of available meals.
     * @return An unordered map containing available meals.
     */
    std::unordered_map<std::string, std::shared_ptr<Meal>> getAvailableMeals() const;

    /**
     * @brief Get the HeadChef overseeing kitchen operations.
     * @return A shared pointer to the HeadChef.
     */
    std::shared_ptr<HeadChef> getHeadChef() const;

    /**
     * @brief Get the DeputyHeadChef responsible for meal preparation.
     * @return A shared pointer to the DeputyHeadChef.
     */
    std::shared_ptr<DeputyHeadChef> getDeputyHeadChef() const;

    /**
     * @brief Generate a list of responsibilities for a chef.
     * @param chefName The name of the chef.
     * @
*/

        std::vector<std::string> generateListOfResposibilties(std::string chefName);

        void createHeadChef();

        void createDeputyHeadChef();

        std::vector<std::shared_ptr<Order>> getPreparedOrders() const;

        std::vector<std::shared_ptr<Order>> getCanceledOrders() const;

        void generateCusines();

        void generateDrinks();        
};

#endif