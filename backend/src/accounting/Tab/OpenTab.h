#ifndef OPENTAB_H
#define OPENTAB_H

#include "TabState.h"

class OpenTab : public TabState
{
public:
    OpenTab(std::shared_ptr<Tab> tab);
    
    json closeTab();
    double getTabTotal();
    json addOrderCost(double cost);
};

#endif