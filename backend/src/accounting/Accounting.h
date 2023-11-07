#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include "Tab.h"
#include "Billing.h"
#include "Inventory.h"

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

        double getBalance();

};

#endif