#include "StationChef.h"
#include "Order.h"
#include "MenuItem.h"
#include "Meal.h"

StationChef::StationChef(std::string name,Kitchen* kitchen) : Chef(name,kitchen){}

StationChef::~StationChef(){}

std::shared_ptr<StationChef> StationChef::getNextChef() const{
    return this->nextStationChef;
}

void StationChef::setNextChefAgain(std::shared_ptr<StationChef> nextChef){
    this->nextStationChef = nextChef;
}