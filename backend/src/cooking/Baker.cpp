#include "Baker.h"
#include "Management.h"
#include "Order.h"
#include "MenuItem.h"
#include "Meal.h"
#include "HeadChef.h"

Baker::Baker(std::shared_ptr<Kitchen> kitchen):Chef("Baker",kitchen){
}

Baker::~Baker(){}

void Baker::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        std::shared_ptr<Chef> next = std::make_shared<HeadChef>(this->kitchen);
        this->setNextChef(next);
        for(auto const& orderItem:order->getMeals()){
            if(kitchen->getAvailableMeals()[orderItem->getName()]->getChef()==this->getName()){
                orderItem->prepare();
            }
        }
        this->nextChef->prepareOrder(order);
    }
}

void Baker::setNextChef(std::shared_ptr<Chef> nextChef){
    this->nextChef = nextChef;
}