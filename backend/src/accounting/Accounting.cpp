#include "Accounting.h"
#include "Billing/CashBill.h"
#include "Billing/CardBill.h"
#include "Billing/MultiBill.h"

Accounting::Accounting() {
    balance = 0.00;
}

Accounting::Accounting(std::shared_ptr<Engine> engine) : GameComponent(engine) {}

Accounting::~Accounting() {}

json Accounting::closeTab() {
    std::shared_ptr<Tab> tab = std::make_shared<Tab>();
    json tabData = tab->closeTab();
    balance += 10;
    return tabData;
}

json Accounting::pay(double amount, std::string paymentType)
{
    if (paymentType == "cash") {
        billing = std::make_shared<Billing>(std::make_shared<CashBill>(amount));
    }
    else if (paymentType == "card") {
        billing = std::make_shared<Billing>(std::make_shared<CardBill>(amount));
    }
    else if (paymentType == "multi") {
        billing = std::make_shared<Billing>(std::make_shared<MultiBill>(amount));
    }
    else {
        return {
            "error", "Invalid payment type"
        };
    }

    json paymentData = billing->pay(amount);
    balance -= amount;
    return paymentData;
}

void Accounting::sendEvent() {}

void Accounting::receiveEvent(std::string event) {
    std::cout << event;
}

double Accounting::getBalance() {
    return balance;
}

void Accounting::setBalance(double balance) {
    this->balance = balance;
}

