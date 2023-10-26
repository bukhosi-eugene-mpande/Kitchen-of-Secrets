#ifndef OVERDUETAB_H
#define OVERDUETAB_H

#include <vector>
#include "TabState.h"

class OverdueTab : public TabState
{
public:
    json closeTab();
    double getBillTotal();
    json addOrderCost(double cost);
};

#endif