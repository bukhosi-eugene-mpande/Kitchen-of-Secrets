#ifndef CASHBILL_H
#define CASHBILL_H

#include "BillStrategy.h"

class CashBill : public BillStrategy
{
public:
    CashBill(double billAmount);
    json pay(double amount);
};

#endif