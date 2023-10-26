#include "StationChef.h"
#include "Order.h"
#include "MenuItem.h"

StationChef::StationChef(std::string name,std::shared_ptr<Kitchen> kitchen) : Chef(name,kitchen){}

StationChef::~StationChef(){}

void StationChef::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        this->setNextChef();
        for(auto const& orderItem:order->getMeals()){
            if(kitchen->getAvailableMeals()[orderItem->getName()]->getChef()==this->getName()){
                orderItem->prepare();
            }
        }
        this->getNextChef()->prepareOrder(order);
    }
}