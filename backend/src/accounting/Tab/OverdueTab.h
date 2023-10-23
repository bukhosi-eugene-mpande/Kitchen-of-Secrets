#ifndef OVERDUETAB_H
#define OVERDUETAB_H

#include <vector>
#include "TabState.h"

class OverdueTab
{
private:
    double billTotal;

public:
    void closeTab();
    double getBillTotal();
    void addOrderCost(double cost);
};

#endif