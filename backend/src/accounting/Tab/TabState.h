#ifndef TABSTATE_H
#define TABSTATE_H

#include <vector>
#include "../../json.hpp"

using json = nlohmann::json;

class Tab;

class TabState
{
protected:
    Tab *tab;
    std::vector<double> orders;

public:
    TabState(Tab *tab);

    virtual json closeTab() = 0;
    virtual double getBillTotal() = 0;
    virtual json addOrderCost(double cost) = 0;
};

#endif