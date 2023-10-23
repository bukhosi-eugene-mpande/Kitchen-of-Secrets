#ifndef TAB_H
#define TAB_H

#include "TabState.h"

class Tab
{
private:
    TabState *state;

public:
    Tab();
    void closeTab();
    double getBillTotal();
    void addOrderCost(double cost);
    void setState(TabState *state);
};

#endif