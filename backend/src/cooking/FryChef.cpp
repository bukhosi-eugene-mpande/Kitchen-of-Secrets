#include "FryChef.h"
#include "GrillChef.h"
#include "Meal.h"

#include "../ordering/Order.h"
#include "../ordering/MenuItem.h"

FryChef::FryChef(Kitchen* Kitchen) : StationChef("Fry Chef",kitchen){
}

FryChef::~FryChef(){}

void FryChef::prepareOrder(std::shared_ptr<Order> order){
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

void FryChef::setNextChef(){
    this->nextStationChef = std::make_shared<GrillChef>(this->getKitchen());
}

