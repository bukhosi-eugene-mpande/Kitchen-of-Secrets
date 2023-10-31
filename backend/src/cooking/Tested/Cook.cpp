#include "Cook.h"
#include "Baker.h"

Cook::Cook(Kitchen* Kitchen) : StationChef("Cook",kitchen){}

Cook::~Cook(){}

void Cook::setNextChef(){
    this->nextStationChef = std::make_shared<Baker>(this->getKitchen());
}
