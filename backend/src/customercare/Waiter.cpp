#include "Waiter.h"

void Waiter::updateCustomerMood(){
    std::cout << "Waiter ----Please note ----> "<< std::endl;
    std::cout << "State has changed to: " << customer->getMood()->getStateName()<< std::endl<< std::endl;
}
