#ifndef Meal_H
#define Meal_H

#include <unordered_map>
#include <string>
#include <memory>

/**
 * @brief The Meal class represents a meal that can be prepared by a chef.
 */
class Meal {
    private:
        std::unordered_map<std::string,int> ingredients; /**< A map of ingredients and their quantities required to prepare the meal. */
        std::string name; /**< The name of the meal. */
        std::string chef; /**< The name of the chef who prepared the meal. */
        double price; /**< The price of the meal. */

    protected: 
        bool isAlcoholic; /**< A flag indicating whether the meal contains alcohol. */

    public:
        /**
         * @brief Constructs a new Meal object.
         * 
         * @param price The price of the meal.
         * @param name The name of the meal.
         * @param chef The name of the chef who prepared the meal.
         * @param ingredients A map of ingredients and their quantities required to prepare the meal.
         */
        Meal(double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients);

        /**
         * @brief Constructs a new Meal object by copying another Meal object.
         * 
         * @param other The Meal object to copy.
         */
        Meal(const Meal& other);

        /**
         * @brief Destroys the Meal object.
         */
        ~Meal();

        /**
         * @brief Sets the name of the meal.
         * 
         * @param name The name of the meal.
         */
        void setName(std::string name);

        /**
         * @brief Gets the name of the meal.
         * 
         * @return The name of the meal.
         */
        std::string getName() const;

        /**
         * @brief Gets the name of the chef who prepared the meal.
         * 
         * @return The name of the chef who prepared the meal.
         */
        std::string getChef() const;

        /**
         * @brief Sets the name of the chef who prepared the meal.
         * 
         * @param chef The name of the chef who prepared the meal.
         */
        void setChef(std::string chef);

        /**
         * @brief Gets the map of ingredients and their quantities required to prepare the meal.
         * 
         * @return The map of ingredients and their quantities required to prepare the meal.
         */
        std::unordered_map<std::string,int> getIngredients() const;

        /**
         * @brief Sets the map of ingredients and their quantities required to prepare the meal.
         * 
         * @param ingredients The map of ingredients and their quantities required to prepare the meal.
         */
        void setIngredients(std::unordered_map<std::string,int> ingredients);

        /**
         * @brief Gets the price of the meal.
         * 
         * @return The price of the meal.
         */
        double getPrice() const;

        /**
         * @brief Sets the price of the meal.
         * 
         * @param price The price of the meal.
         */
        void setPrice(double price);

        /**
         * @brief Gets a flag indicating whether the meal contains alcohol.
         * 
         * @return A flag indicating whether the meal contains alcohol.
         */
        bool getIsAlcoholic() const;

};

#endif
