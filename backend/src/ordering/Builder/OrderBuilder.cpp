#include "OrderBuilder.h"

/**
 * The OrderBuilder constructor initializes a new Order object.
 */
OrderBuilder::OrderBuilder()
{
    this->order= new Order();
}

/**
 * The destructor for the OrderBuilder class deletes the order object.
 */
OrderBuilder::~OrderBuilder()
{
    delete order;
}

/**
 * The build() function creates a new Order object and returns a pointer to the previously created
 * Order object.
 * 
 * @return The build() function is returning a pointer to an Order object.
 */
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