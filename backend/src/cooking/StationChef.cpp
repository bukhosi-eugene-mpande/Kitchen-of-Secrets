#include "StationChef.h"
#include "Meal.h"

#include "../ordering/Order.h"
#include "../ordering/MenuItem.h"

StationChef::StationChef(std::string name,Kitchen* kitchen) : Chef(name,kitchen){}

StationChef::~StationChef(){}

std::shared_ptr<StationChef> StationChef::getNextChef() const{
    return this->nextStationChef;
}

void StationChef::setNextChefAgain(std::shared_ptr<StationChef> nextChef){
    this->nextStationChef = nextChef;
}