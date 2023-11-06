/**
 * @file CustomerNPC.h
 * @brief Contains the declaration of the CustomerNPC class.
 */

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
 * @class CustomerNPC
 * @brief Represents a non-player character (NPC) customer in the restaurant.
 *
 * The CustomerNPC class represents an NPC customer in the restaurant. It is derived from the CustomerTemplate class and includes NPC-specific behaviors and attributes.
 */
class CustomerNPC: public CustomerTemplate {
public:
    /**
     * @brief Constructor for the CustomerNPC class.
     * @param management A shared pointer to the player interaction management.
     */
    CustomerNPC(std::shared_ptr<PlayerInteraction> management);

    /**
     * @brief Constructor for the CustomerNPC class with options for the number of guests and seating section.
     * @param management A shared pointer to the player interaction management.
     * @param hasGuests A boolean indicating whether the customer has guests.
     * @param section The seating section for the customer.
     */
    CustomerNPC(std::shared_ptr<PlayerInteraction> management, bool hasGuests, std::string section);

    /**
     * @brief Destructor for the CustomerNPC class.
     */
    ~CustomerNPC();

    /**
     * @brief Generate a random number of guests within a specified range.
     * @param min The minimum number of guests.
     * @param max The maximum number of guests.
     * @return The randomly generated number of guests.
     */
    int generateRandomAmmountOfGuests(int min, int max);
};

#endif
