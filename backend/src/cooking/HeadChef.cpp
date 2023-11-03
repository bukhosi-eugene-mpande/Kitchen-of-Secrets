#include "HeadChef.h"

HeadChef::HeadChef(Kitchen* kitchen,Management* management) : Chef("Head Chef",kitchen){ 
    this->kitchen=kitchen;
    this->management = management;
}

HeadChef::~HeadChef(){}

std::string HeadChef::getName() const{
    return this->name;
}

Kitchen* HeadChef::getKitchen() const{
    return this->kitchen;
}

void HeadChef::goOnRounds(){
    /**
     * @todo implement this function
     * 
     */
}

void HeadChef::handleComplaint(){
    /**
     * @todo implement this function
     * 
     */
}
