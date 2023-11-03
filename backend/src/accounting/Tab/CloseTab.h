#ifndef CLOSE_TAB_H
#define CLOSE_TAB_H

#include <vector>
#include "TabState.h"

class CloseTab : public TabState {
    public:
        /**
         * @brief Construct a new Close Tab object
         * 
         * @param tab 
         */
        CloseTab(std::shared_ptr<Tab> tab);

        /**
         * @brief Results in the Customer closing an open tab.
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