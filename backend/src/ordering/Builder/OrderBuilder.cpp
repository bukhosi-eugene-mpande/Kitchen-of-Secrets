#include "OrderBuilder.h"

OrderBuilder::OrderBuilder()
{
    this->order= new Order();
}

OrderBuilder::~OrderBuilder()
{
    delete order;
}

Order* OrderBuilder::build()
{
    Order* result= this->order;
    this->order= new Order();
    return result;
}