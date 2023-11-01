#include "VeryUnhappy.h"

VeryUnhappy::VeryUnhappy(std::shared_ptr<CustomerTemplate> customer) : SatisfactionState("VeryUnhappy", customer, 0.3, 0.0){
    this->customer->leave();
}

void VeryUnhappy::console(){
    /**
     * @brief customer is already very unhappy, so no need to change mood because the customer will leave
     * 
     */
}

void VeryUnhappy::anger(){
    /**
     * @brief customer is already very unhappy, so no need to change mood because the customer will leave
     * 
     */
}