#include "DeputyHeadChef.h"
#include "FryChef.h"
#include "Order.h"
#include "MenuItem.h"
#include "Management.h"
#include "Meal.h"

DeputyHeadChef::DeputyHeadChef(Kitchen* kitchen) : StationChef("Deputy Head Chef",kitchen){
    this->management = nullptr;
    this->flag = false;
}


DeputyHeadChef::~DeputyHeadChef(){} 

void DeputyHeadChef::setNextChef(){
    this->nextStationChef = std::make_shared<FryChef>(this->getKitchen());
}

void DeputyHeadChef::cancelOrder(std::shared_ptr<Order> order){
    this->getKitchen()->cancelOrder(order);
}

void DeputyHeadChef::finishOrder(std::shared_ptr<Order> order){
    this->getKitchen()->finishOrder(order);
}

void DeputyHeadChef::prepareOrder(std::shared_ptr<Order> order){
    if(management==nullptr){
        this->setManagement();
    }
    if(order!=nullptr){
        if(order->IsFinished() && this->flag){
            this->finishOrder(order);
            return;
        }
        std::unordered_map<std::string,int> ingredients = order->calculateIngredients();
        if(this->management->requestIngredients(ingredients)){
            this->flag = true;
            for(int i = 0; i < order->getMeals().size(); i++){
                if(this->kitchen->getChefName(order->getMeals()[i]->getName())==this->getName()){
                    order->getMeals()[i]->prepare();
                }
            }
            this->setNextChef();
            this->getNextChef()->setKitchen(this->getKitchen());
            this->getNextChef()->prepareOrder(order);            
        }else{
            this->cancelOrder(order);
            return;
        }
    }
}


Kitchen* DeputyHeadChef::getKitchen() const{
    return this->kitchen;
}

void DeputyHeadChef::setManagement(){
    this->management = this->getKitchen()->getManagement();
}