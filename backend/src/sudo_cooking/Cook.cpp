#include "Cook.h"
#include "Baker.h"
#include "Meal.h"

#include "../ordering/Order.h"
#include "../ordering/MenuItem.h"

Cook::Cook(std::shared_ptr<Engine> engine, Kitchen* Kitchen) : StationChef(engine, kitchen, "Cook") {
    this->kitchen=kitchen;
}

Cook::~Cook() {}

void Cook::prepareOrder(std::shared_ptr<Order> order){
    for(int i = 0; i < (int) order->getMeals().size(); i++){
        if(this->kitchen->getChefName(order->getMeals()[i]->getName())==this->getName()){
            order->getMeals()[i]->prepare();
        }
    }
    this->setNextChef();
    this->getNextChef()->setKitchen(this->getKitchen());
    this->getNextChef()->prepareOrder(order); 
}

void Cook::setNextChef(){
    this->nextStationChef = std::make_shared<Baker>(this->getKitchen());
}

void Cook::sendEvent() {
    std::string event = "Order Completed.";
    engine->notify(shared_from_this(), event);
}

void Cook::receiveEvent(std::string event) {
    if (event == "Prepare Order") {
        //TODO: NEED TO FIND A WAY TO GET THE ACTUAL ORDER
        prepareOrder(getOrder());
    }
}