#ifndef CUSTOMERNPC_H
#define CUSTOMERNPC_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "CustomerTemplate.h"
class Menu;

class CustomerNPC: public CustomerTemplate{
    private:
        std::vector<CustomerNPC> guests;

    public:
        CustomerNPC(std::shared_ptr<Management> management);

        ~CustomerNPC();

        void addGuest(CustomerNPC guest);

        std::vector<CustomerNPC> getGuests();

        std::unordered_map<std::string,int> generateBeverageOrder(Menu menu);

        std::unordered_map<std::string,int> generateFoodOrder(Menu menu);
        
};

#endif