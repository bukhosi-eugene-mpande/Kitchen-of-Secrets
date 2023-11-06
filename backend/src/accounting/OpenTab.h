#ifndef OPENTAB_H
#define OPENTAB_H

#include "TabState.h"

class OpenTab : public TabState{
    public:
        OpenTab(Tab *tab);
        std::string closeTab();
        double getBillTotal();
        std::string addOrderCost(double cost);
};

#endif