#ifndef TAB_H
#define TAB_H

#include "TabState.h"

class Tab
{
private:
    TabState *state;

public:
    Tab();
    json closeTab();
    double getBillTotal();
    json addOrderCost(double cost);
    void setState(TabState *state);
};

#endif