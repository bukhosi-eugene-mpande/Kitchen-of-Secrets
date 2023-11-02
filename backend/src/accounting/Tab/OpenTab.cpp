#include "OpenTab.h"
#include "Tab.h"
#include "CloseTab.h"

OpenTab::OpenTab(std::shared_ptr<Tab> tab) : TabState(tab) {}

json OpenTab::closeTab()
{
    tab->setState(std::make_shared<CloseTab>(tab));

    return {
        {"status", "success"},
        {"message", "Tab closed successfully"}};
}

double OpenTab::getTabTotal()
{
    double total = 0.0;

    for (double cost : orders)
    {
        total += cost;
    }

    return total;
}

json OpenTab::addOrderCost(double cost)
{
    orders.push_back(cost);

    return {
        {"status", "success"},
        {"message", "Order added successfully"}};
}
