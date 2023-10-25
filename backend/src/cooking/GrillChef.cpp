#include "GrillChef.h"
#include "Management.h"
#include "Order.h"
#include "MenuItem.h"
#include "Meal.h"
#include "Cook.h"

GrillChef::GrillChef(std::shared_ptr<Kitchen> kitchen):StationChef("Grill Chef",kitchen){}

GrillChef::~GrillChef(){}

void GrillChef::prepareOrder(std::shared_ptr<Order> order){
    if(order!=nullptr){
        std::shared_ptr<Cook> next = std::make_shared<Cook>(this->kitchen);
        this->setNextChef(next);
        for(auto const& orderItem:order->getMeals()){
            if(kitchen->getAvailableMeals()[orderItem->getName()]->getChef()==this->getName()){
                orderItem->prepare();
            }
        }
        this->getNextChef()->prepareOrder(order);
    }
}
