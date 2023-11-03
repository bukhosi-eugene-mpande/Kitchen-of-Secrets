#include "DeputyHeadChef.h"
#include "FryChef.h"
#include "Meal.h"

#include "../ordering/Order.h"
#include "../ordering/MenuItem.h"
#include "../sudo_management/Management.h"

DeputyHeadChef::DeputyHeadChef(std::shared_ptr<Engine> engine, Kitchen *kitchen) : StationChef(engine, kitchen, "Deputy Head Chef")
{
    this->management = nullptr;
    this->flag = false;
}

DeputyHeadChef::~DeputyHeadChef() {}

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
        if(order->IsFinished()){
            this->finishOrder(order);
            return;
        }
        std::unordered_map<std::string,int> ingredients = order->calculateIngredients();
        if(this->management->requestIngredients(ingredients)){
            for(int i = 0; i < (int) order->getMeals().size(); i++){
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

void DeputyHeadChef::sendEvent()
{
    //TODO: NEED EXPLANATION AS TO IF THE DEPUTY HEAD CHEF NEEDS TO SEND ANYTHING.
}

void DeputyHeadChef::receiveEvent(std::string event)
{
     //TODO: NEED EXPLANATION AS TO IF THE DEPUTY HEAD CHEF NEEDS TO RECEIVE ANYTHING.
}
