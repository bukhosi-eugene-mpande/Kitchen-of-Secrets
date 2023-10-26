#include "Cook.h"
#include "Baker.h"

Cook::Cook(std::shared_ptr<Kitchen> kitchen) : StationChef("Cook",kitchen){}

Cook::~Cook(){}

void Cook::setNextChef(){
    this->nextStationChef = std::make_shared<Baker>(this->getKitchen());
}
