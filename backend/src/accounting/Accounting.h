#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include "Tab/Tab.h"
#include "Billing/Billing.h"
#include "Inventory/Inventory.h"

class Accounting
{
private:
    double balance;

    Tab *tab;
    Billing *billing;
    Inventory *inventory;

public:
    Accounting();

    json closeTab();
    json pay(double amount, std::string paymentType);

    ~Accounting();
};

#endif