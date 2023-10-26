#include "DeputyHeadChef.h"
#include "FryChef.h"
#include "Order.h"
#include "MenuItem.h"
#include "Management.h"

DeputyHeadChef::DeputyHeadChef(std::shared_ptr<Kitchen> kitchen,std::shared_ptr<Management> management) : Chef("Deputy Head Chef",kitchen){
    this->management = management;
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
