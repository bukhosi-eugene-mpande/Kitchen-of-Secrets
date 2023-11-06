#ifndef OVERDUETAB_H
#define OVERDUETAB_H

#include <vector>
#include "TabState.h"

class OverdueTab : public TabState {
    public:
        OverdueTab(Tab *tab);
        std::string closeTab();
        double getBillTotal();
        std::string addOrderCost(double cost);
};

#endif