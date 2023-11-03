#ifndef OPENTAB_H
#define OPENTAB_H

#include "TabState.h"

class OpenTab : public TabState
{
public:
    OpenTab(Tab *tab);
    
    json closeTab();
    double getBillTotal();
    json addOrderCost(double cost);
};

#endif