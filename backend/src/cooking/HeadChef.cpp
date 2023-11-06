#include "HeadChef.h"
#include "../customercare/CustomerTemplate.h"
#include "../reservation/Section.h"
#include "../reservation/Table.h"

HeadChef::HeadChef(Kitchen* kitchen,PlayerInteraction* management) : Chef("Head Chef",kitchen){ 
    this->kitchen=kitchen;
    this->management = management;
}

HeadChef::~HeadChef(){}

std::string HeadChef::getName() const{
    return this->name;
}

Kitchen* HeadChef::getKitchen() const{
    return this->kitchen;
}

void HeadChef::goOnRounds(){
    
    std::vector<std::shared_ptr<Table>> tables = this->management->getGeneralSection()->getTables();
    for(int i = 0; i < (int)tables.size(); i++){
        std::shared_ptr<Table> table = tables[i];
        std::vector<std::shared_ptr<CustomerTemplate>> customers = table->getCustomers();
        for(int j = 0; j < (int)customers.size(); j++){
           customers[j]->console();
        }
    }

    tables.clear();
    tables = this->management->getPrivateSection()->getTables();

    for(int i = 0; i < (int)tables.size(); i++){
        std::shared_ptr<Table> table = tables[i];
        std::vector<std::shared_ptr<CustomerTemplate>> customers = table->getCustomers();
        for(int j = 0; j < (int)customers.size(); j++){
           customers[j]->console();
        }
    }

}

