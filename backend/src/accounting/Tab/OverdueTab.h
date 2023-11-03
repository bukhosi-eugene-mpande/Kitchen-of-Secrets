#ifndef OVERDUETAB_H
#define OVERDUETAB_H

#include <vector>
#include "TabState.h"

class OverdueTab : public TabState {
    public:
        /**
         * @brief Construct a new Overdue Tab object
         * 
         * @param tab 
         */
        OverdueTab(Tab *tab);

        /**
         * @brief 
         * 
         * @return json 
         */
        json closeTab();

        /**
         * @brief Get the Tab Total object
         * 
         * @return double 
         */
        double getTabTotal();

        /**
         * @brief 
         * 
         * @param cost 
         * @return json 
         */
        json addOrderCost(double cost);
};

#endif