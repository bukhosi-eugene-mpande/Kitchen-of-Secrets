#ifndef CARDBILL_H
#define CARDBILL_H

#include "BillStrategy.h"

class CardBill : public BillStrategy
{
public:
    CardBill(double billAmount);
    json pay(double amount);
};

#endif