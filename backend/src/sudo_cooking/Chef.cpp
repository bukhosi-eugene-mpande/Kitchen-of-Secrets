#include "Chef.h"

Chef::Chef(std::shared_ptr<Engine> engine, Kitchen *kitchen, std::string name) : GameComponent(engine) {
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
