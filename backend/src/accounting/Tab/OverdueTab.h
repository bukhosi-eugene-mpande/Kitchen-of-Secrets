#ifndef OVERDUETAB_H
#define OVERDUETAB_H

#include <vector>
#include "TabState.h"

class OverdueTab : public TabState
{
public:
    OverdueTab(Tab *tab);
    
    json closeTab();
    double getTabTotal();
    json addOrderCost(double cost);
};

#endif