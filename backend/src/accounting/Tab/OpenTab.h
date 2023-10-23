#ifndef OPENTAB_H
#define OPENTAB_H

#include "TabState.h"

class OpenTab
{
private:
    double billLimit;

public:
    void closeTab();
    double getBillTotal();
    void addOrderCost(double cost);
};

#endif