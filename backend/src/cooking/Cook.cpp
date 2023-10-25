#include "Cook.h"
#include "Management.h"
#include "Order.h"
#include "MenuItem.h"
#include "Meal.h"
#include "Baker.h"

Cook::Cook(std::shared_ptr<Kitchen> kitchen) : StationChef("Cook",kitchen){}

Cook::~Cook(){}

void Cook::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        std::shared_ptr<Baker> next = std::make_shared<Baker>(this->kitchen);
        this->setNextChef(next);
        for(auto const& orderItem:order->getMeals()){
            if(kitchen->getAvailableMeals()[orderItem->getName()]->getChef()==this->getName()){
                orderItem->prepare();
            }
        }
        this->getNextChef()->prepareOrder(order);
    }
}
