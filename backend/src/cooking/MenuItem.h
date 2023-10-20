#ifndef MenuItem_H
#define MenuItem_H

#include <unordered_map>
#include <string>
#include <memory>

/**
 * @brief The MenuItem class represents a menu item in a restaurant.
 * 
 * This class contains information about the name of the menu item, the ingredients needed to make it,
 * and methods for calculating the price and ingredients needed to make the menu item.
 */

class MenuItem {
    protected:
    std::unordered_map<std::string,int> mealIngredients; /**< A map of ingredient names to their quantities */
    std::string name; /**< The name of the menu item */
    double mealPrice; /**< The price of the menu item */
    bool isPrepared; /**< A boolean value indicating whether the menu item has been prepared */

    public:
        /**
         * @brief Constructs a new MenuItem object with the given name and ingredients.
         * 
         * @param name The name of the menu item
         * @param ingredients A map of ingredient names to their quantities
         * @param price The price of the menu item
         */
        MenuItem(double price,std::string name, std::unordered_map<std::string,int> ingredients);

        /**
         * @brief Copy constructor for MenuItem objects.
         * 
         * @param other The MenuItem object to copy
         */
        MenuItem(const MenuItem& other);

        /**
         * @brief Destroys the MenuItem object.
         */
        virtual ~MenuItem();

        /**
         * @brief Creates a copy of the MenuItem object.
         * 
         * @return A shared pointer to the copied MenuItem object 
         *      
         * */
        virtual std::shared_ptr<MenuItem> clone() const = 0;

        /**
         * @brief Prepares the menu item for serving.
         * 
         * This method simulates the process of preparing the menu item for serving.
         */
        virtual void prepare() = 0;

        /**
         * @brief Gets the name of the menu item.
         * 
         * @return The name of the menu item
         */
        std::string getName() const;

        /**
         * @brief Gets the ingredients needed to make the menu item.
         * 
         * @return A map of ingredient names to their quantities
         */
        std::unordered_map<std::string,int> getMealIngredients() const;

        double getMealPrice() const;

        bool getIsPrepared() const;
        
};

#endif

