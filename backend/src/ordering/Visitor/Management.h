#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "Element.h"
#include "Order.h"
#include "Visitor.h"
#include <iostream>
#include <map>
#include <string>

class Management 
{
public:
    Management();
    void sendOrder(Order* order);
    Order* receiveOrder();
    void sendPaymentType(std::string sendPaymentType);
    //void accept(Visitor* visitor) override;
};

#endif 
/*The management will act as 

1. an elemnet to be visited by a visitor
in  the context of the visitor pattern

2. It also interacts with the Waiter 
(in the context of the Builder pattern) 
by receiving orders from the waiter 
and giving completed orders to the waiter.*/
