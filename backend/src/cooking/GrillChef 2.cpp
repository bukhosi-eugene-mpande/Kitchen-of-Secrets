#include "GrillChef.h"
#include "Cook.h"
#include "Order.h"
#include "Meal.h"
#include "MenuItem.h"

GrillChef::GrillChef(std::shared_ptr<Engine> engine, std::shared_ptr<Kitchen> kitchen) : StationChef(engine, kitchen, "Grill Chef") {}

GrillChef::~GrillChef() {}

void GrillChef::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        for(int i = 0; i < order->getMeals().size(); i++){
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

void Baker::sendEvent() {
}

void Baker::receiveEvent(std::string event) {
    if (event == "Prepare Order") {
        prepareOrder(getOrder());
    }
}