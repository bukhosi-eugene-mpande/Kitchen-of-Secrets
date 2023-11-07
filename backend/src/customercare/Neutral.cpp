#include "Neutral.h"
#include "Happy.h"
#include "Unhappy.h"

Neutral::Neutral(CustomerTemplate* customer) : SatisfactionState("Neutral", customer, 0.0, 0.0) {}

void Neutral::console(){
    this->customer->setMood(std::make_shared<Happy>(this->customer));
}

void Neutral::anger(){
    this->customer->setMood(std::make_shared<Unhappy>(this->customer));
}