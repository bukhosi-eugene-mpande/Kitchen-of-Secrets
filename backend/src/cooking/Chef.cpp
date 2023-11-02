#include "Chef.h"

Chef::Chef(std::shared_ptr<Engine> engine, std::shared_ptr<Kitchen> kitchen, std::string name) : GameComponent(engine) {
    this->kitchen = kitchen;
    this->name = name;
}

Chef::~Chef() {}

std::string Chef::getName() const{
    return this->name;
}

void Chef::setKitchen(std::shared_ptr<Kitchen> kitchen) {
    this->kitchen = kitchen;
}

std::shared_ptr<Kitchen> Chef::getKitchen() const{
    return this->kitchen;
}
