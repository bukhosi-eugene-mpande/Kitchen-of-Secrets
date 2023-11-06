/**
 * @file Meal.h
 * @brief Contains the declaration of the Meal class.
 */

#ifndef Meal_H
#define Meal_H

#include <unordered_map>
#include <string>
#include <memory>

/**
 * @class Meal
 * @brief Represents a meal item in the restaurant menu.
 *
 * The Meal class represents a meal item in the restaurant menu. It includes information about the meal's name, chef, price, ingredients, and whether it is alcoholic.
 */
class Meal {
private:
    std::unordered_map<std::string, int> ingredients; /**< A map of ingredients and their quantities required for the meal. */
    std::string name; /**< The name of the meal. */
    std::string chef; /**< The chef responsible for preparing the meal. */
    double price; /**< The price of the meal. */
    bool isAlcoholic; /**< Indicates whether the meal is alcoholic (true) or non-alcoholic (false). */

public:
    /**
     * @brief Constructor for the Meal class.
     * @param price The price of the meal.
     * @param name The name of the meal.
     * @param chef The chef responsible for preparing the meal.
     * @param ingredients A map of ingredients and their quantities required for the meal.
     */
    Meal(double price, std::string name, std::string chef, std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Copy constructor for the Meal class.
     * @param other Another Meal object to copy from.
     */
    Meal(const Meal& other);

    /**
     * @brief Destructor for the Meal class.
     */
    ~Meal();

    /**
     * @brief Set the name of the meal.
     * @param name The name of the meal.
     */
    void setName(std::string name);

    /**
     * @brief Get the name of the meal.
     * @return A string containing the name of the meal.
     */
    std::string getName() const;

    /**
     * @brief Get the chef responsible for preparing the meal.
     * @return A string containing the name of the chef.
     */
    std::string getChef() const;

    /**
     * @brief Set the chef responsible for preparing the meal.
     * @param chef The name of the chef.
     */
    void setChef(std::string chef);

    /**
     * @brief Get the map of ingredients and their quantities required for the meal.
     * @return A map of ingredients and their quantities.
     */
    std::unordered_map<std::string, int> getIngredients() const;

    /**
     * @brief Set the map of ingredients and their quantities required for the meal.
     * @param ingredients A map of ingredients and their quantities.
     */
    void setIngredients(std::unordered_map<std::string, int> ingredients);

    /**
     * @brief Get the price of the meal.
     * @return The price of the meal.
     */
    double getPrice() const;

    /**
     * @brief Set the price of the meal.
     * @param price The price of the meal.
     */
    void setPrice(double price);

    /**
     * @brief Check if the meal is alcoholic.
     * @return true if the meal is alcoholic, false if it is non-alcoholic.
     */
    bool getIsAlcoholic() const;
};

#endif
