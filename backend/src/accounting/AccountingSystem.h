#ifndef ACCOUNTING_SYSTEM_H
#define ACCOUNTING_SYSTEM_H

#include "Tab/Tab.h"
#include "Billing/Billing.h"
#include "Inventory/Inventory.h"

#include <memory>

class AccountingSystem {
    private:
        double balance;
        std::shared_ptr<Tab> tab;
        std::shared_ptr<Billing> billing;
        std::shared_ptr<Inventory> inventory;
    public:
        AccountingSystem();
        ~AccountingSystem();
        double getBalance();
        void setBalance(double balance);
        std::shared_ptr<Tab> getTab();
        void setTab(std::shared_ptr<Tab> tab);
        std::shared_ptr<Billing> getBilling();
        void setBilling(std::shared_ptr<Billing> billing);
        std::shared_ptr<Inventory> getInventory();
        void setInventory(std::shared_ptr<Inventory> inventory);
        json closeTab();
        json pay(double amount, std::string paymentType);
};

#endif