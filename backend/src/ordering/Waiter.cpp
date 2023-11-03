// TODO: implement the class
#include "Waiter.h"

Waiter::Waiter(std::shared_ptr<Engine> engine) : GameComponent(engine) {}

Waiter::~Waiter() {}

void Waiter::takeOrder(){

}

void Waiter::serveOrder(){

}

double Waiter::billOrder(){
    return 0;
}

void Waiter::sendOrdersToKitchen(){

}

void Waiter::giveOrderToCustomer(){

}

std::shared_ptr<MenuItem> Waiter::createFoodItem(){
    return nullptr;
}

std::shared_ptr<MenuItem> Waiter::createDrinkItem(){
    return nullptr;
}

std::shared_ptr<Menu> Waiter::createMenu(){
    return nullptr;
}

std::shared_ptr<Order> Waiter::getCanceledOrderFromKitchen(){
   return nullptr;
}

std::shared_ptr<Order> Waiter::getOrderFromKitchen(){
    return nullptr;
}

void Waiter::buildOrder(){

}

int Waiter::getId(){
    return 0;
}

void Waiter::sendEvent()
{
    std::string event = "Send Order To Kitchen.";
    engine->notify(shared_from_this(), event);
}

void Waiter::receiveEvent(std::string event)
{
    if (event == "Customer Is Ready To Order.") {
        takeOrder();
    }
    if (event == "Give Order To Customer.") {
        giveOrderToCustomer();
    }
    if (event == "Cancel Order.") {
        //TODO: POSSIBLY getCanceledOrderFromKitchen() BUT I DON'T WANT TO RETURN ANYTHING
    }
}
