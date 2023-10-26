#ifndef BILLSTRATEGY_H
#define BILLSTRATEGY_H

#include "../json.hpp"

using json = nlohmann::json;

class BillStrategy
{
protected:
    double billAmount;

public:
    BillStrategy(double billAmount);
    virtual json pay(double amount) = 0;
};

#endif