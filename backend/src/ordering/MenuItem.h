#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <unordered_map>
#include <string>
#include <memory>

/**
 * @brief The MenuItem class represents a menu item that can be ordered by a customer.
 * 
 * It contains information about the name, price, ingredients, and preparation status of the item.
 */
class MenuItem{
    protected:
        /**
         * @brief A map of ingredient names to their quantities required for the meal.
         */
        std::unordered_map<std::string, int> mealIngredients;

        /**
         * @brief The name of the menu item.
         */
        std::string name;

        /**
         * @brief The price of the menu item.
         */
        double mealPrice; 

        /**
         * @brief A flag indicating whether the menu item has been prepared or not.
         */
        bool isPrepared;

    public:
        /**
         * @brief Constructs a new MenuItem object with the given price, name, and ingredients.
         * 
         * @param price The price of the menu item.
         * @param name The name of the menu item.
         * @param ingredients A map of ingredient names to their quantities required for the meal.
         */
        MenuItem(double price, std::string name, std::unordered_map<std::string, int> ingredients);

        /**
         * @brief Constructs a new MenuItem object by copying another MenuItem object.
         * 
         * @param other The MenuItem object to copy.
         */
        MenuItem(const MenuItem& other);

        /**
         * @brief Destroys the MenuItem object.
         */
        virtual ~MenuItem();

        /**
         * @brief Creates a new MenuItem object that is a copy of this object.
         * 
         * @return A shared pointer to the new MenuItem object.
         */
        virtual std::shared_ptr<MenuItem> clone() = 0;

        /**
         * @brief Prepares the menu item for serving.
         */
        void prepare();

        /**
         * @brief Returns the name of the menu item.
         * 
         * @return The name of the menu item.
         */
        std::string getName() const;

        /**
         * @brief Returns a map of ingredient names to their quantities required for the meal.
         * 
         * @return A map of ingredient names to their quantities required for the meal.
         */
        std::unordered_map<std::string,int> getMealIngredients() const;
        
        /**
         * @brief Returns the price of the menu item.
         * 
         * @return The price of the menu item.
         */
        double getMealPrice() const;

        /**
         * @brief Returns whether the menu item has been prepared or not.
         * 
         * @return True if the menu item has been prepared, false otherwise.
         */
        bool getIsPrepared() const;
};

#endif

