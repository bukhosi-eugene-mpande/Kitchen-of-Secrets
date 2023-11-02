#include "Unhappy.h"
#include "VeryUnhappy.h"
#include "Neutral.h"

Unhappy::Unhappy() : SatisfactionState() {}

Unhappy::~Unhappy() {}

void Unhappy::helpMe(std::shared_ptr<Customer> mood, std::string complaints) {
    std::shared_ptr<std::vector<std::string>> complaint = mood->getComplaints();
    auto it = std::find(complaint->begin(), complaint->end(), complaints);
    if (it != complaint->end()) {
        complaint->erase(it);
    }
    mood->setMood(std::make_shared<Neutral>());
}

void Unhappy::timeLaps(std::shared_ptr<Customer> mood, std::string complaints) {
    mood->getComplaints()->clear();
    mood->setMood(std::make_shared<VeryUnhappy>());
}

double Unhappy::getTip(){
    return 2.25;
}

std::string Unhappy::getStateName(){
    return "Unhappy";
}