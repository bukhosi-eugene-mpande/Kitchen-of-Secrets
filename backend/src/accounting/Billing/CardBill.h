#ifndef CARDBILL_H
#define CARDBILL_H

#include "BillStrategy.h"

class CardBill : public BillStrategy
{
public:
    CardBill(double billAmount);
    void pay(double amount);
};

#endif