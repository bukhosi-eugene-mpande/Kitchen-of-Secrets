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

    public:
        CustomerNPC(std::shared_ptr<Management> management);

        CustomerNPC(std::shared_ptr<Management> management,bool hasGuests,std::string section);

        ~CustomerNPC();

        int generateRandomAmmountOfGuests(int min, int max);
        
};

#endif