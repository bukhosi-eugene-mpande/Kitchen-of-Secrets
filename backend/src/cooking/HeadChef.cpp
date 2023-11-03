#include "HeadChef.h"

HeadChef::HeadChef(std::shared_ptr<Engine> engine, std::shared_ptr<Kitchen> kitchen, std::string name, std::shared_ptr<Management> management) : Chef(engine, kitchen, name) {
    this->management = management;
}

HeadChef::~HeadChef() {}

std::string HeadChef::getName() const{
    return this->name;
}

std::shared_ptr<Kitchen> HeadChef::getKitchen() const {
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

void HeadChef::sendEvent() {}

void HeadChef::receiveEvent(std::string event) {
    if (event == "Go On Rounds") {
        goOnRounds();
    }
    if (event == "Handle Complaint") {
        handleComplaint();
    }
}
