#ifndef WAITER_H
#define WAITER_H
#include "OrderBuilder.h"

//this is the Director of the Design Patterns
class Waiter{
    private:
        OrderBuilder* builder;
    public:
        void setBuilder();
        Order* takeOrder();
};
#endif