#ifndef CARDBILL_H
#define CARDBILL_H

#include "BillStrategy.h"
#include <string>

class CardBill : public BillStrategy{
    public:
        CardBill(double billAmount);
        std::string pay(double amount);
};

#endif