#include "Baker.h"
#include "Management.h"
#include "Order.h"
#include "MenuItem.h"
#include "Meal.h"
#include "DeputyHeadChef.h"

Baker::Baker(std::shared_ptr<Kitchen> kitchen) : StationChef("Baker",kitchen){
}

Baker::~Baker(){}

void Baker::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        std::shared_ptr<DeputyHeadChef> next = std::make_shared<DeputyHeadChef>(this->kitchen);
        this->setNextChef(next);
        for(auto const& orderItem:order->getMeals()){
            if(kitchen->getAvailableMeals()[orderItem->getName()]->getChef()==this->getName()){
                orderItem->prepare();
            }
        }
        this->getNextChef()->prepareOrder(order);
    }
}
