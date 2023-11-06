#ifndef BILLSTRATEGY_H
#define BILLSTRATEGY_H

#include <string>

class BillStrategy {
    protected:
        double billAmount;

    public:
        BillStrategy(double billAmount);
        virtual std::string pay(double amount) = 0;
};

#endif