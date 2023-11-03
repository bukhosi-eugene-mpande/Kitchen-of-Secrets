#include "Baker.h"
#include "DeputyHeadChef.h"
#include "Meal.h"

#include "../ordering/Order.h"
#include "../ordering/MenuItem.h"

Baker::Baker(Kitchen* Kitchen) : StationChef("Baker",kitchen){
    this->kitchen=kitchen;
}

Baker::~Baker(){}

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
