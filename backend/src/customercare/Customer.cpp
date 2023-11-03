#include "Customer.h"
#include "Happy.h"

Customer::Customer(std::shared_ptr<Engine> engine, std::shared_ptr<PlayerInteraction> management) : CustomerTemplate(engine, "Main Character", management) {
    this->hasGuests = false;
    this->isMain = true;
}

Customer::~Customer() {}

void Customer::sendEvent() {
    std::string event1 = "Customer(s) Requests To Be Seated.";
    std::string event2 = "Customer Is Ready To Order.";
    std::string event3 = "Customer(s) Leave.";
    std::string event4 = "Cancel Order.";
    engine->notify(shared_from_this(), event1);
    engine->notify(shared_from_this(), event2);
    engine->notify(shared_from_this(), event3);
    engine->notify(shared_from_this(), event4);
}

void Customer::receiveEvent(std::string event) {
    std::cout << event;
}