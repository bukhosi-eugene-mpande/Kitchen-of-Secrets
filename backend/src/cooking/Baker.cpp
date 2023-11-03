#include "Baker.h"
#include "DeputyHeadChef.h"
#include "Meal.h"

#include "../ordering/Order.h"
#include "../ordering/MenuItem.h"

Baker::Baker(std::shared_ptr<Engine> engine, Kitchen* Kitchen) : StationChef(engine, kitchen, "Baker") {
    this->kitchen=kitchen;
}

Baker::~Baker() {}

void Baker::prepareOrder(std::shared_ptr<Order> order){
    for(int i = 0; i < (int) order->getMeals().size(); i++){
        if(this->kitchen->getChefName(order->getMeals()[i]->getName())==this->getName()){
            order->getMeals()[i]->prepare();
        }
    }
    this->setNextChef();
    this->getNextChef()->setKitchen(this->getKitchen());
    this->getNextChef()->prepareOrder(order); 
}

void Baker::setNextChef(){
    this->nextStationChef = std::make_shared<DeputyHeadChef>(this->getKitchen());
}

void Baker::sendEvent() {
    std::string event = "Order Completed.";
    engine->notify(shared_from_this(), event);
}

void Baker::receiveEvent(std::string event) {
    if (event == "Prepare Order") {
        //TODO: NEED TO FIND A WAY TO GET THE ACTUAL ORDER
        prepareOrder(getOrder());
    }
}
