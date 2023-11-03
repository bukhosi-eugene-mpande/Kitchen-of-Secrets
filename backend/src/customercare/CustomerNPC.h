#ifndef CUSTOMER_NPC_H
#define CUSTOMER_NPC_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "CustomerTemplate.h"
class Menu;

class CustomerNPC: public CustomerTemplate {
    public:
        CustomerNPC(std::shared_ptr<Management> management);
        CustomerNPC(std::shared_ptr<Management> management, bool hasGuests, std::string section);
        ~CustomerNPC();
        std::unordered_map<std::string, int> generateBeverageOrder(Menu menu);
        std::unordered_map<std::string, int> generateFoodOrder(Menu menu);
        int generateRandomAmmountOfGuests(int min, int max);
};

#endif