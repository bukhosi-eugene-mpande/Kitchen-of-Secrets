#ifndef CHEF_H
#define CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"

/**
 * @brief The Chef class represents a chef in the kitchen.
 * 
 */
class Chef{
    protected:
        Kitchen *kitchen;

        std::string name;

    public:
        /**
         * @brief Construct a new Chef object
         * 
         * @param name The name of the chef
         * @param kitchen The kitchen where the chef works
         */
        Chef(std::string name, Kitchen *kitchen);

        /**
         * @brief Destroy the Chef object
         * 
         */
        ~Chef();

        /**
         * @brief Get the name of the chef
         * 
         * @return std::string The name of the chef
         */
        std::string getName() const;

        /**
         * @brief Set the kitchen where the chef works
         * 
         * @param kitchen The kitchen where the chef works
         */
        void setKitchen(Kitchen *kitchen);

        /**
         * @brief Get the kitchen where the chef works
         * 
         * @return Kitchen* The kitchen where the chef works
         */
        Kitchen* getKitchen() const;

};

#endif