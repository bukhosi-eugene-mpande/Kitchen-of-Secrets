#ifndef MULTIBILL_H
#define MULTIBILL_H

#include "BillStrategy.h"

class MultiBill : public BillStrategy
{
public:
    void pay(double amount);
};

#endif