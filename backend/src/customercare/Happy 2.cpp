#include "Happy.h"
#include "Neutral.h"

Happy::Happy() : SatisfactionState() {}

Happy::~Happy() {}

void Happy::helpMe(std::shared_ptr<Customer> mood, std::string complaints) {}

void Happy::timeLaps(std::shared_ptr<Customer> mood, std::string complaints) {
    mood->getComplaints()->push_back(complaints);
    mood->setMood(std::make_shared<Neutral>());
}

double Happy::getTip() {
    return 10.00;
}