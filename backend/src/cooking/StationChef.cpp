#include "StationChef.h"
#include "Order.h"
#include "MenuItem.h"
#include "Meal.h"


StationChef::StationChef(std::shared_ptr<Engine> engine, std::shared_ptr<Kitchen> kitchen, std::string name) : Chef(engine, kitchen, name) {}

StationChef::~StationChef() {}

std::shared_ptr<StationChef> StationChef::getNextChef() const{
    return this->nextStationChef;
}

void StationChef::setNextChefAgain(std::shared_ptr<StationChef> nextChef){
    this->nextStationChef = nextChef;
}