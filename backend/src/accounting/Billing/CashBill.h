#ifndef CASHBILL_H
#define CASHBILL_H

#include "BillStrategy.h"

class CashBill : public BillStrategy
{
public:
    void pay(double amount);
};

#endif