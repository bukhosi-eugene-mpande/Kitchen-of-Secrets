#ifndef OPENTAB_H
#define OPENTAB_H

#include "TabState.h"

class OpenTab : public TabState
{
public:
    /**
     * @brief Construct a new Open Tab object
     * 
     * @param tab 
     */
    OpenTab(std::shared_ptr<Tab> tab);
    
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