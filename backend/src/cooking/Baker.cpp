#include "Baker.h"
#include "DeputyHeadChef.h"

Baker::Baker(std::shared_ptr<Kitchen> kitchen) : StationChef("Baker",kitchen){}

Baker::~Baker(){}

void Baker::setNextChef(){
    this->nextStationChef = std::make_shared<DeputyHeadChef>(this->getKitchen());
}
