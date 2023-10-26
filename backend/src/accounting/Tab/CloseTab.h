#ifndef CLOSETAB_H
#define CLOSETAB_H

#include <vector>
#include "TabState.h"

class CloseTab : public TabState
{
public:
    json closeTab();
    double getBillTotal();
    json addOrderCost(double cost);
};

#endif