#include "GrillChef.h"
#include "Cook.h"
#include "Meal.h"

#include "../ordering/Order.h"
#include "../ordering/MenuItem.h"

GrillChef::GrillChef(std::shared_ptr<Engine>, Kitchen* kitchen) : StationChef(engine, kitchen, "Grill Chef") {
    this->kitchen=kitchen;
}

GrillChef::~GrillChef() {}

void GrillChef::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        for(int i = 0; i < (int) order->getMeals().size(); i++){
            if(this->kitchen->getChefName(order->getMeals()[i]->getName())==this->getName()){
                order->getMeals()[i]->prepare();
            }
        }
        this->setNextChef();
        this->getNextChef()->setKitchen(this->getKitchen());
        this->getNextChef()->prepareOrder(order); 
    }
}

void GrillChef::setNextChef(){
    this->nextStationChef = std::make_shared<Cook>(this->getKitchen());
}

void GrillChef::sendEvent() {
    std::string event = "Order Completed.";
    engine->notify(shared_from_this(), event);
}

void GrillChef::receiveEvent(std::string event) {
    if (event == "Prepare Order") {
        //TODO: NEED TO FIND A WAY TO GET THE ACTUAL ORDER
        prepareOrder(getOrder());
    }
}