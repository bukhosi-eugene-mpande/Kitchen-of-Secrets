#include "FryChef.h"
#include "GrillChef.h"

FryChef::FryChef(Kitchen* Kitchen) : StationChef("Fry Chef",kitchen){}

FryChef::~FryChef(){}

void FryChef::setNextChef(){
    this->nextStationChef = std::make_shared<GrillChef>(this->getKitchen());
}

