#include "Cook.h"
#include "Baker.h"
#include "Order.h"
#include "Meal.h"
#include "MenuItem.h"

Cook::Cook(std::shared_ptr<Engine> engine, std::shared_ptr<Kitchen> kitchen) : StationChef(engine, kitchen, "Cook") {}

Cook::~Cook() {}

void Cook::prepareOrder(std::shared_ptr<Order> order){
    for(int i = 0; i < order->getMeals().size(); i++){
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
