#ifndef BILLSTRATEGY_H
#define BILLSTRATEGY_H

class BillStrategy
{
protected:
    double billAmount;

public:
    BillStrategy(double billAmount);
    virtual void pay(double amount) = 0;
};

#endif