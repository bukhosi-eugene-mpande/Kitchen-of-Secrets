#include "GrillChef.h"
#include "Cook.h"
#include "Meal.h"

#include "../ordering/Order.h"
#include "../ordering/MenuItem.h"

GrillChef::GrillChef(Kitchen* kitchen):StationChef("Grill Chef",kitchen){
    this->kitchen=kitchen;
}

GrillChef::~GrillChef(){}

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
