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

void Waiter::serveOrder()
{
    // Order* order = management->receiveOrder();
    // std::cout << "Received order from management:\n";
    // order->listItems();

    // delete order;
}
void Waiter::accept(Visitor* visitor)
{
    visitor->visit(this);
}

/* --------------BUILDER DESIGN PATTERN------------------------
    Waiter as a Director in Builder Pattern: In the context of the 
    Builder pattern, the Waiter acts as a director that constructs an 
    Order using an OrderBuilder. The Waiter doesn’t need to know how 
    the order is built, it just tells the builder what parts to 
    build (e.g., add food, add drink).
*/


/*---------------VISITOR DESIGN PATTERN-------------------------
    Waiter as an Element in Visitor Pattern: 
    In the context of the Visitor pattern, 
    the Waiter is an element that can 
    be visited by a visitor. The visitor 
    defines what happens when it visits the Waiter.
*/