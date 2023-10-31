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
/*
    1. request Menu from Kitchen via Management
    2. turn it into an unordered_map
    3. When customer leaves, tell management to tell reservations to set table to null
    4. When order is canceled, waiter kicks out customer
    5. 
*/