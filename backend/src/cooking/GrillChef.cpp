#include "GrillChef.h"
#include "Cook.h"

GrillChef::GrillChef(Kitchen* kitchen):StationChef("Grill Chef",kitchen){}

GrillChef::~GrillChef(){}

void GrillChef::setNextChef(){
    this->nextStationChef = std::make_shared<Cook>(this->getKitchen());
}
