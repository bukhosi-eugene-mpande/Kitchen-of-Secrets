#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "MenuItem.h"
#include "AbstractOrder.h"

/**
 * @brief A class representing a beverage menu item.
 * 
 */
class Beverage : public MenuItem, AbstractOrder{
        bool isAlcoholic;
    public:
        /**
         * @brief Construct a new Beverage object.
         * 
         * @param isAlcoholic Whether the beverage is alcoholic or not.
         * @param price The price of the beverage.
         * @param name The name of the beverage.
         * @param ingredients The ingredients of the beverage.
         */
        Beverage(bool isAlcoholic,double price,std::string name, std::unordered_map<std::string,int> ingredients);

        /**
         * @brief Destroy the Beverage object.
         * 
         */
        ~Beverage();

        /**
         * @brief Copy constructor for Beverage.
         * 
         * @param other The Beverage object to copy.
         */
        Beverage(const Beverage& other);

        /**
         * @brief Calculates the price of the beverage.
         * 
         * @return The price of the beverage.
         */
        double calculatePrice();

        /**
         * @brief Calculates the ingredients of the beverage.
         * 
         * @return The ingredients of the beverage.
         */
        std::unordered_map<std::string,int> calculateIngredients();

        /**
         * @brief Clones the Beverage object.
         * 
         * @return A shared pointer to the cloned Beverage object.
         */
        std::shared_ptr<MenuItem> clone() override;

        /**
         * @brief Gets whether the beverage is alcoholic or not.
         * 
         * @return True if the beverage is alcoholic, false otherwise.
         */
        bool getIsAlcoholic() const;
};

#endif