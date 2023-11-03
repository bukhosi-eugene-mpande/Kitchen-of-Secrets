#ifndef BILLING_H
#define BILLING_H

#include "BillStrategy.h"

class Billing
{
private:
    BillStrategy *billStrategy;

public:
    Billing(BillStrategy *billStrategy);
    json pay(double amount);
};

#endif