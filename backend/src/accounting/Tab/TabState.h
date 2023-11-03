#ifndef TABSTATE_H
#define TABSTATE_H

#include <vector>
#include "../../json.hpp"

using json = nlohmann::json;

class Tab;

class TabState {
    protected:
        std::shared_ptr<Tab> tab;
        std::vector<double> orders;
    
    public:
        TabState(std::shared_ptr<Tab> tab);
    
        virtual json closeTab() = 0;
        virtual double getTabTotal() = 0;
        virtual json addOrderCost(double cost) = 0;
};

#endif