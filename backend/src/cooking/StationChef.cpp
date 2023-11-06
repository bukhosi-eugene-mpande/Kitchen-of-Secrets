#include "StationChef.h"
#include "Meal.h"


StationChef::StationChef(Kitchen *kitchen, std::string name) : Chef(name,kitchen) {}

StationChef::~StationChef() {}

std::shared_ptr<StationChef> StationChef::getNextChef() const{
    return this->nextStationChef;
}

void StationChef::setNextChefAgain(std::shared_ptr<StationChef> nextChef){
    this->nextStationChef = nextChef;
}