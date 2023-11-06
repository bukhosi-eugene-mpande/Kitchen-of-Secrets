/**
 * The Management class in this C++ code receives an order from a waiter, sends it to the kitchen,
 * receives the completed order from the kitchen, and sends the payment type to accounting.
 */
#include "Management.h"

Management::Management()
{}

/**
 * The sendOrder function in the Management class receives an order from the waiter and sends it to the
 * kitchen.
 * 
 * @param order The "order" parameter is a pointer to an object of type "Order".
 */
void Management::sendOrder(Order* order) 
{
    // Send the order to the kitchen and wait for it to be ready
    std::cout << "Management received< the order >from the waiter.\n"<<order<<std::endl;
    std::cout<< "Management proceeds to send it to Kitchen"<<std::endl;
    std::cout<<std:: endl;
}


/**
 * The receiveOrder function in the Management class receives a completed order from the kitchen and
 * returns it.
 * 
 * @return The function `receiveOrder()` is returning a pointer to an `Order` object.
 */
Order* Management::receiveOrder()
{
    // Receive the completed order from the kitchen
    std::cout << "Management received the completed order from the kitchen.\n";
    std::cout <<"Management proceeds to send order to waiter"<<std::endl;
    std::cout<<std::endl;
    // For testing purposes, let's create a dummy order
    Order* order = new Order();
    order->items = {{"Pumpkin Soup", 7.99}, {"Bloody Mary", 5.99}};
    
    return order;
}


/**
 * The function "sendPaymentType" in the Management class receives a payment type from a waiter and
 * sends it to the accounting department.
 * 
 * @param paymentType The paymentType parameter is a string that represents the type of payment
 * received from the waiter.
 */
void Management::sendPaymentType(std::string paymentType)
{
    std::cout<<"Management receives payment type from waiter"<<std::endl;
    std::cout<<"Management sends it over to accounting: "<<paymentType<<std::endl;
    std::cout<<std::endl;
}

