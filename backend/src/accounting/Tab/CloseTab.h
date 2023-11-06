#ifndef CLOSETAB_H
#define CLOSETAB_H

#include <vector>
#include "TabState.h"

class CloseTab : public TabState
{
public:
    CloseTab(Tab *tab);
    
    std::string closeTab();
    double getBillTotal();
    std::string addOrderCost(double cost);
};

#endif