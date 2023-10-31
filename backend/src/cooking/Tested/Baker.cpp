#include "Baker.h"
#include "DeputyHeadChef.h"

Baker::Baker(Kitchen* Kitchen) : StationChef("Baker",kitchen){}

Baker::~Baker(){}

void Baker::setNextChef(){
    this->nextStationChef = std::make_shared<DeputyHeadChef>(this->getKitchen());
}
