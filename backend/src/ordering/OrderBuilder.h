#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H
#include "Order.h"
#include <memory>
//this is the Builer Participant in Order Builder
class OrderBuilder
{
    protected:
         Order*order;
    public:
        OrderBuilder();
        ~OrderBuilder();
        virtual void addDrink()=0;
        virtual void addFood()=0;
        Order* build();
};
#endif