#ifndef CUSTOMER_NPC_H
#define CUSTOMER_NPC_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "CustomerTemplate.h"
#include "../management/PlayerInteraction.h"
class Menu;

/**
 * @brief The CustomerNPC class represents a non-playable customer in the game.
 * 
 * This class inherits from the CustomerTemplate class and provides additional functionality
 * for generating a random amount of guests.
 */
class CustomerNPC: public CustomerTemplate {
    public:
        /**
         * @brief Constructs a new CustomerNPC object with the given management interaction.
         * 
         * @param management A shared pointer to the PlayerInteraction object that manages the game.
         */
        CustomerNPC(std::shared_ptr<PlayerInteraction> management);

        /**
         * @brief Constructs a new CustomerNPC object with the given management interaction, 
         *        guest status, and section.
         * 
         * @param management A shared pointer to the PlayerInteraction object that manages the game.
         * @param hasGuests A boolean indicating whether the customer has guests or not.
         * @param section A string representing the section of the restaurant the customer is in.
         */
        CustomerNPC(std::shared_ptr<PlayerInteraction> management, bool hasGuests, std::string section);

        /**
         * @brief Destroys the CustomerNPC object.
         * 
         */
        ~CustomerNPC();

        /**
         * @brief Generates a random amount of guests between the given minimum and maximum values.
         * 
         * @param min The minimum number of guests to generate.
         * @param max The maximum number of guests to generate.
         * @return int The randomly generated number of guests.
         */
        int generateRandomAmmountOfGuests(int min, int max);
};

#endif