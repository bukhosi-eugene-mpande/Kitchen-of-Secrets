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

class CustomerNPC: public CustomerTemplate {
    public:
        CustomerNPC(std::shared_ptr<PlayerInteraction> management);
        CustomerNPC(std::shared_ptr<PlayerInteraction> management, bool hasGuests, std::string section);
        ~CustomerNPC();
        int generateRandomAmmountOfGuests(int min, int max);
};

#endif