#ifndef TABSTATE_H
#define TABSTATE_H

class TabState
{
public:
    virtual void closeTab() = 0;
    virtual double getBillTotal() = 0;
    virtual void addOrderCost(double cost) = 0;
};

#endif