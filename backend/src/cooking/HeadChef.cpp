#include "HeadChef.h"
#include "Management.h"
#include "Order.h"
#include "MenuItem.h"
#include "Meal.h"
#include "FryChef.h"

HeadChef::HeadChef(std::shared_ptr<Kitchen> kitchen):Chef("Head Chef",kitchen){
}

HeadChef::~HeadChef(){}

void HeadChef::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        if(order->IsFinished()){
            this->finishOrder(order);
        }else{
            if(this->kitchen->getManagement()->requestIngredients(order->getIngredients())){
                std::shared_ptr<Chef> next = std::make_shared<FryChef>(this->kitchen);
                this->setNextChef(next);
                for(auto const& orderItem:order->getMeals()){
                    if(kitchen->getAvailableMeals()[orderItem->getName()]->getChef()==this->getName()){
                        orderItem->prepare();
                    }
                }
                this->nextChef->prepareOrder(order);
            }
            else{
                this->cancelOrder(order);
            }
        }
    }
}

void HeadChef::setNextChef(std::shared_ptr<Chef> nextChef){
    this->nextChef = nextChef;
}

void HeadChef::cancelOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        order->setIsCancelled(true);
        this->kitchen->cancelOrder(order);
    }
}

void HeadChef::finishOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        this->kitchen->finishOrder(order);
    }
}