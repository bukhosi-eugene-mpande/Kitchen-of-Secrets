#include "Chef.h"

Chef::Chef(std::string name,Kitchen *kitchen){
    this->kitchen = kitchen;
    this->name = name;
}

Chef::~Chef() {}

std::string Chef::getName() const{
    return this->name;
}

void Chef::setKitchen(Kitchen *kitchen) {
    this->kitchen = kitchen;
}

Kitchen* Chef::getKitchen() const{
    return this->kitchen;
}
