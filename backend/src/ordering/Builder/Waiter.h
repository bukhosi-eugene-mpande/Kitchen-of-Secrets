#ifndef WAITER_H
#define WAITER_H
#include "OrderBuilder.h"
#include "Element.h"
#include "Visitor.h"
#include "Management.h"
#include "Customer.h" 
//this is the Director of the Design Patterns
class Waiter{
    private:
        OrderBuilder* builder;
        Management* management;
        Customer* customer;
    public:
        Waiter(Management* management, Customer* customer);
        void setBuilder(OrderBuilder* builder);
        void takeOrder();
        void serveOrder(Customer* customer);
        void accept(Visitor* visitor);
        //Order* giveOrder();
        
};
#endif