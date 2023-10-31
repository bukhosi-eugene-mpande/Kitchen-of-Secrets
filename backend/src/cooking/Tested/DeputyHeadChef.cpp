#include "DeputyHeadChef.h"
#include "FryChef.h"
#include "Order.h"
#include "MenuItem.h"
#include "Management.h"
#include "Meal.h"

DeputyHeadChef::DeputyHeadChef(Kitchen* kitchen) : Chef("Deputy Head Chef",kitchen){
    this->nextChef = nullptr;
    this->management = nullptr;
}


DeputyHeadChef::~DeputyHeadChef(){} 

void DeputyHeadChef::setNextChef(){
    this->nextChef = std::make_shared<FryChef>(this->getKitchen());
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
        if(order->IsFinished()){
            this->finishOrder(order);
            return;
        }
        std::unordered_map<std::string,int> ingredients = order->calculateIngredients();
        if(this->management->requestIngredients(ingredients)){
            this->setNextChef();
            for(auto const& orderItem:order->getMeals()){
                if(kitchen->getAvailableMeals()[orderItem->getName()]->getChef()==this->getName()){
                    orderItem->prepare();
                }
            }
            this->getNextChef()->prepareOrder(order);
        }else{
            this->cancelOrder(order);
            return;
        }
    }
}

std::shared_ptr<Chef> DeputyHeadChef::getNextChef() const{
    return this->nextChef;
}

Kitchen* DeputyHeadChef::getKitchen() const{
    return this->kitchen;
}

void DeputyHeadChef::setManagement(){
    this->management = this->getKitchen()->getManagement();
}