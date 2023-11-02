#ifndef MULTIBILL_H
#define MULTIBILL_H

#include "BillStrategy.h"

class MultiBill : public BillStrategy
{
public:
    MultiBill(double billAmount);
    json pay(double amount);
};

#endif