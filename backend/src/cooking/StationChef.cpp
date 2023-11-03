#include "StationChef.h"
#include "Meal.h"


StationChef::StationChef(std::shared_ptr<Engine> engine, Kitchen *kitchen, std::string name) : Chef(engine, kitchen, name) {}

StationChef::~StationChef() {}

std::shared_ptr<StationChef> StationChef::getNextChef() const{
    return this->nextStationChef;
}

void StationChef::setNextChefAgain(std::shared_ptr<StationChef> nextChef){
    this->nextStationChef = nextChef;
}