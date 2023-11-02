#include <cstdlib> 
#include <ctime> 

#include "CustomerNPC.h"
#include "../ordering/Menu.h"

CustomerNPC::CustomerNPC(std::shared_ptr<Management> management) : CustomerTemplate("NPC",management){}

CustomerNPC::CustomerNPC(std::shared_ptr<Management> management,bool hasGuests,std::string DisiredSection) : CustomerTemplate("NPC",management){
    this->hasGuests = hasGuests;
    this->DesiredSection = DesiredSection;
    if(DisiredSection == "Private Section"){
        int numGuests = this->generateRandomAmmountOfGuests(1,10);
        for(int i = 0; i < numGuests; i++){
            CustomerNPC guest = CustomerNPC(management);
            this->addGuest(guest);
        }
    }else{
        int numGuests = this->generateRandomAmmountOfGuests(1,5);
        for(int i = 0; i < numGuests; i++){
            CustomerNPC guest = CustomerNPC(management);
            this->addGuest(guest);
        }
    }
}

CustomerNPC::~CustomerNPC(){}

void CustomerNPC::addGuest(CustomerNPC guest){
    this->guests.push_back(guest);
    this->numGuests++;
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

int CustomerNPC::generateRandomAmmountOfGuests(int min, int max){
    srand(time(0)); 
    return min + rand() % (max - min + 1); 
}