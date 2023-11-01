#include "CustomerNPC.h"
#include "../ordering/Menu.h"

CustomerNPC::CustomerNPC(std::shared_ptr<Management> management) : CustomerTemplate("NPC",management){}

CustomerNPC::~CustomerNPC(){}

void CustomerNPC::addGuest(CustomerNPC guest){
    this->guests.push_back(guest);
}

std::vector<CustomerNPC> CustomerNPC::getGuests(){
    return this->guests;
}

std::unordered_map<std::string,int> CustomerNPC::generateBeverageOrder(Menu menu){
    // TODO: Implement way to automatically generate order
    std::unordered_map<std::string,int> order;
    return order;
}

std::unordered_map<std::string,int> CustomerNPC::generateFoodOrder(Menu menu){
    // TODO: Implement way to automatically generate order
    std::unordered_map<std::string,int> order;
    return order; 
}

