#ifndef TABSTATE_H
#define TABSTATE_H

#include "Tab.h"
#include <vector>
#include "../json.hpp"

using json = nlohmann::json;

class TabState
{
protected:
    Tab *tab;
    std::vector<double> orders;

public:
    virtual json closeTab() = 0;
    virtual double getBillTotal() = 0;
    virtual json addOrderCost(double cost) = 0;
};

#endif