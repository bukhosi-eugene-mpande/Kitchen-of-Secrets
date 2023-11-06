#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include "Tab/Tab.h"
#include "Billing/Billing.h"
#include "Inventory/Inventory.h"

class Accounting{
    private:
        double balance;

        Tab *tab;
        Billing *billing;
        Inventory *inventory;

    public:
        Accounting();
        ~Accounting();

        std::string closeTab();
        std::string pay(double amount, std::string paymentType);

};

#endif