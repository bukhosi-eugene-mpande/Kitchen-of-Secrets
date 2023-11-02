#ifndef CLOSETAB_H
#define CLOSETAB_H

#include <vector>
#include "TabState.h"

class CloseTab : public TabState
{
public:
    CloseTab(std::shared_ptr<Tab> tab);
    
    json closeTab();
    double getTabTotal();
    json addOrderCost(double cost);
};

#endif