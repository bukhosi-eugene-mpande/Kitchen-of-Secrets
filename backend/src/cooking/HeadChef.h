#ifndef HEAD_CHEF_H
#define HEAD_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

#include "../management/PlayerInteraction.h"

/**
 * @class HeadChef
 * @brief A class representing a head chef in a kitchen.
 * 
 * This class inherits from the Chef class and adds additional functionality for managing the kitchen.
 */
class HeadChef : public Chef {
    private:
        PlayerInteraction* management; ///< A pointer to the player interaction object.

        std::string name; ///< The name of the head chef.

    public:
        /**
         * @brief Construct a new Head Chef object
         * 
         * @param kitchen A pointer to the kitchen object.
         * @param management A pointer to the player interaction object.
         */
        HeadChef(Kitchen* kitchen,PlayerInteraction* management);

        /**
         * @brief Destroy the Head Chef object
         * 
         */
        ~HeadChef();

        /**
         * @brief Get the name of the head chef.
         * 
         * @return std::string The name of the head chef.
         */
        std::string getName() const;

        /**
         * @brief Get a pointer to the kitchen object.
         * 
         * @return Kitchen* A pointer to the kitchen object.
         */
        Kitchen* getKitchen() const;
        
        /**
         * @brief Perform rounds of the kitchen.
         * 
         */
        void goOnRounds();
};

#endif