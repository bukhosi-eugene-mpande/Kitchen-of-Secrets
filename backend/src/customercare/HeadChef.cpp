#include "HeadChef.h" 

void HeadChef::updateCustomerMood(){
    std::cout << "HeadChef ----Please note ----> "<< std::endl;
    std::cout << "State has changed to: " << customer->getMood()->getStateName()<< std::endl<< std::endl;
}
