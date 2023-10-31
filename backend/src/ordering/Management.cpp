#include "Management.h"

Management::Management()
{}

void Management::sendOrder(Order* order) 
{
    // Send the order to the kitchen and wait for it to be ready
    std::cout << "Management received< the order >from the waiter.\n"<<order<<std::endl;
    std::cout<< "Management proceeds to send it to Kitchen"<<std::endl;
    std::cout<<std:: endl;
}


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


void Management::sendPaymentType(std::string paymentType)
{
    std::cout<<"Management receives payment type from waiter"<<std::endl;
    std::cout<<"Management sends it over to accounting: "<<paymentType<<std::endl;
    std::cout<<std::endl;
}

