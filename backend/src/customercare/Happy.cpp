#include "Happy.h"
#include "Neutral.h"

Happy::Happy(std::shared_ptr<Customer> customer) : SatisfactionState("Happy", customer, 0.0, 0.2){

}

void Happy::console(){
    this->customer->setMood(std::make_shared<Neutral>(this->customer));
}

void Happy::anger(){
    this->customer->setMood(std::make_shared<Neutral>(this->customer));
}