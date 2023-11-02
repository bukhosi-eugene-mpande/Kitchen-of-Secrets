#ifndef TAB_H
#define TAB_H

#include "TabState.h"
#include "backend/src/management/GameComponent.h"

class Tab : GameComponent
{
private:
    std::shared_ptr<TabState> state;

public:
    Tab(std::shared_ptr<Engine> engine);
    json closeTab();
    double getTabTotal();
    json addOrderCost(double cost);
    void setState(std::shared_ptr<TabState> state);
    
};

#endif