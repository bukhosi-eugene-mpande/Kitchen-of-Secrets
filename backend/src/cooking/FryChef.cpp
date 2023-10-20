#include "FryChef.h"
#include "Management.h"
#include "Order.h"
#include "MenuItem.h"
#include "Meal.h"
#include "GrillChef.h"

FryChef::FryChef(std::shared_ptr<Kitchen> kitchen):Chef("Fry Chef",kitchen){
}

FryChef::~FryChef(){}

void FryChef::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        std::shared_ptr<Chef> next = std::make_shared<GrillChef>(this->kitchen);
        this->setNextChef(next);
        for(auto const& orderItem:order->getMeals()){
            if(kitchen->getAvailableMeals()[orderItem->getName()]->getChef()==this->getName()){
                orderItem->prepare();
            }
        }
        this->nextChef->prepareOrder(order);
    }
}

void FryChef::setNextChef(std::shared_ptr<Chef> nextChef){
    this->nextChef = nextChef;
}
