#include "AccountingSystem.h"
#include "Billing/CashBill.h"
#include "Billing/CardBill.h"
#include "Billing/MultiBill.h"

AccountingSystem::AccountingSystem() {
    balance = 0.0;
}

AccountingSystem::~AccountingSystem() {}

json AccountingSystem::closeTab() {
    std::shared_ptr<Tab> tab = std::make_shared<Tab>();
    json tabData = tab->closeTab();
    balance += 10;
    return tabData;
}

json AccountingSystem::pay(double amount, std::string paymentType)
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

double AccountingSystem::getBalance() {
    return balance;
}

void AccountingSystem::setBalance(double balance) {
    this->balance = balance;
}

std::shared_ptr<Tab> AccountingSystem::getTab() {
    return tab;
}

void AccountingSystem::setTab(std::shared_ptr<Tab> tab) {
    this->tab = tab;
}

std::shared_ptr<Billing> AccountingSystem::getBilling() {
    return billing;
}

void AccountingSystem::setBilling(std::shared_ptr<Billing> billing) {
    this->billing = billing;
}

std::shared_ptr<Inventory> AccountingSystem::getInventory() {
    return inventory;
}

void AccountingSystem::setInventory(std::shared_ptr<Inventory> inventory) {
    this->inventory = inventory;
}