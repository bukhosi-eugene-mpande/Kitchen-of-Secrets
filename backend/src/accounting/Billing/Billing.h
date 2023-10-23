#ifndef BILLING_H
#define BILLING_H

#include "BillStrategy.h"

class Billing
{
private:
    BillStrategy *billStrategy;

public:
    void pay(double amount);
};

#endif