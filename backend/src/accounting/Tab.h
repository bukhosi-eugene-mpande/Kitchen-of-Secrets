#ifndef TAB_H
#define TAB_H

#include "TabState.h"

class Tab{
    private:
        TabState *state;

    public:
        Tab();
        std::string closeTab();
        double getBillTotal();
        std::string addOrderCost(double cost);
        void setState(TabState *state);
};

#endif