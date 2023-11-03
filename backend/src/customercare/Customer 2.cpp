#include "Customer.h"
#include "Happy.h"

Customer::Customer(std::shared_ptr<Engine> engine) : GameComponent(engine) {
    mood = std::make_shared<Happy>();
    complaints = std::make_shared<std::vector<std::string>>();
    totalBill = 0.00;
    totalTab = 0.00;
}

Customer::~Customer() {}

std::shared_ptr<SatisfactionState> Customer::getMood(){
    return mood;
}

void Customer::setMood(std::shared_ptr<SatisfactionState> mood){
    notify();
    this->mood = mood;
}

std::shared_ptr<std::vector<std::string>> Customer::getComplaints(){
    return complaints;
}

void Customer::setComplaints(std::shared_ptr<std::vector<std::string>> complaints) {
    this->complaints = complaints;
}

std::shared_ptr<Billing> Customer::getBill() {
    return bill;
}

void Customer::setBill(std::shared_ptr<Billing> bill) {
    this->bill = bill;
}

std::shared_ptr<Tab> Customer::getTab() {
    return tab;
}

void Customer::setTab(std::shared_ptr<Tab> tab) {
    this->tab = tab;
}

double Customer::getTip() {
    return mood->getTip();
}

void Customer::setTotalBill(double totalBill) {
    this->totalBill = totalBill + getTip();
}

double Customer::getTotalBill(){
    return totalBill;
}

double Customer::getTotalTab() {
    return tab->getTabTotal();
}

void Customer::setTotalTab(double tabAmount){
    tab->addOrderCost(tabAmount);
}

void Customer::closeTab() {
    tab->closeTab();
}

void Customer::makePayment() {
    bill->pay(totalBill);
}

void Customer::helpMe(){
    mood->helpMe(this, "waiting too long");
}

void Customer::timeLaps(){
    mood->timeLaps(this, "waiting too long");
}

void Customer::sendEvent() {
}

void Customer::receiveEvent(std::string event)
{
    if (event == "Order Served") {
        if (getMood() == Neutral) {
            setMood(Happy);
        } else if (getMood() = Unhappy) {
            setMood(Unhappy);
        }
    }
}

std::string Customer::toString(){
    std::stringstream ss;

    ss << "State: " << mood->getStateName() << std::endl;

    ss << "complaints:" << std::endl;
    for (const auto &complaints : *complaints)
    {
        ss << complaints << std::endl;
    }

    return ss.str();
}