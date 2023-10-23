#ifndef CLOSETAB_H
#define CLOSETAB_H

#include <vector>
#include "TabState.h"

class CloseTab
{
private:
    std::vector<double> orders;

public:
    void closeTab();
    double getBillTotal();
    void addOrderCost(double cost);
};

#endif