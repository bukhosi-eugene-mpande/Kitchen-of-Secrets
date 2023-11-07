#ifndef CASHBILL_H
#define CASHBILL_H

#include "BillStrategy.h"

class CashBill : public BillStrategy{
    public:
        CashBill(double billAmount);
        std::string pay(double amount);
};

#endif