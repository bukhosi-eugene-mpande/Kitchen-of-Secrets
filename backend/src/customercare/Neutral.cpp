#include "Neutral.h"
#include "Happy.h"
#include "Unhappy.h"

Neutral::Neutral() : SatisfactionState(){}

Neutral::~Neutral() {}

void Neutral::helpMe(std::shared_ptr<Customer> mood, std::string complaints) {
    mood->getComplaints()->clear();
    mood->setMood(std::shared_ptr<Happy>());
}

void Neutral::timeLaps(std::shared_ptr<Customer> mood, std::string complaints) {
    mood->getComplaints()->push_back(complaints);
    mood->setMood(std::make_shared<Unhappy>());
}

double Neutral::getTip() {
    return 5.00;
}

std::string Neutral::getStateName() {
    return"Neutral";
}