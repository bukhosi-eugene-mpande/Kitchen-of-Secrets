#ifndef OPENTAB_H
#define OPENTAB_H

#include "TabState.h"

class OpenTab : public TabState
{
public:
    json closeTab();
    double getBillTotal();
    json addOrderCost(double cost);
};

#endif