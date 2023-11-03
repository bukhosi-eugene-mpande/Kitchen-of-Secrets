#ifndef TAB_H
#define TAB_H

#include "TabState.h"
#include "backend/src/management/GameComponent.h"
#include "backend/src/cooking/Order.h"

class Tab : GameComponent
{
private:
    std::shared_ptr<TabState> state;
    double tabTotal;
    std::vector<std::shared_ptr<Order>> orderedItems;
public:
    Tab(std::shared_ptr<Engine> engine);
    json closeTab();
    double getTabTotal();
    json addOrderCost(double cost);
    void setState(std::shared_ptr<TabState> state);
    double calculateOrderCost(const std::vector<std::shared_ptr<Order>> orderedItems);
    std::vector<std::shared_ptr<Order>> getOrderedItems();
    virtual void sendEvent();
    virtual void receiveEvent(std::string event);
    
};

#endif