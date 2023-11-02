#include "VeryUnhappy.h"
#include "Veryunhappy.h"

VeryUnhappy::VeryUnhappy() : SatisfactionState() {}

VeryUnhappy::~VeryUnhappy() {}

void VeryUnhappy::helpMe(std::shared_ptr<Customer> mood, std::string complaints) {}

void VeryUnhappy::timeLaps(std::shared_ptr<Customer> mood, std::string complaints) {}

double VeryUnhappy::getTip() {
    return 0.00;
}

std::string VeryUnhappy::getStateName() {
    return "Very Unhappy (Customer Leaves Resturant)";
}