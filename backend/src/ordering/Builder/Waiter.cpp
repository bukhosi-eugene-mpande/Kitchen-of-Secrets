#include "Waiter.h"
//#include "Management.h"

// Waiter::Waiter(Management* management)
// {
//     this->management=management;
// }

void Waiter::setBuilder(OrderBuilder* builder)
{
    this->builder=builder;
}

void Waiter::takeOrder()
{
    builder->addDrink();
    builder->addFood();
    Order* order= builder->build();
    std::cout<<"Sending the order to management"<<std::endl;
    order->listItems();

    //management->sendOrder(order);

    delete order;
}