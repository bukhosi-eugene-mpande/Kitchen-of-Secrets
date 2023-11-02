#include "Waiter.h"
//#include "Management.h"

Waiter::Waiter(Management* management, Customer* customer)
{
    this->management=management;
    this->customer=customer;
}

void Waiter::setBuilder(OrderBuilder* builder)
{
    this->builder=builder;
}

void Waiter::takeOrder()
{
    //this function send paymentType to manager
    management->sendPaymentType(customer->getPaymentOfChoice());

    //here we are building the order
    builder->addDrink();
    
    builder->addFood();
    Order* order= builder->build();
    std::cout<<"---Sending this the order to management: ---"<<std::endl;
    order->listItems();

    //here we send order to management
    management->sendOrder(order);

    //cleanup
    delete order;
}

void Waiter::serveOrder(Customer* customer)
{
    //we take order from management
    Order* order = management->receiveOrder();
    std::cout << "---Received order from management & Serves to client: ---\n";

    //we list the order to make sure its correct
    order->listItems();

    //the customer eats their  food
    customer->eatFood();
    delete order;
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