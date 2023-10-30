#ifndef WAITER_H
#define WAITER_H
#include "OrderBuilder.h"
#include "Element.h"
#include "Visitor.h"
//#include "Management.h"

//this is the Director of the Design Patterns
class Waiter{
    private:
        OrderBuilder* builder;
        //Management* management;
    public:
        //Waiter(Management* management);
        void setBuilder(OrderBuilder* builder);
        void takeOrder();
        void serveOrder();
        void accept(Visitor* visitor);
        
};
#endif