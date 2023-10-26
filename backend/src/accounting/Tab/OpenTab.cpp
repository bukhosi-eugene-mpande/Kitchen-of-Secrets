#include "OpenTab.h"
#include "Tab.h"
#include "CloseTab.h"

OpenTab::OpenTab(Tab *tab) : TabState(tab) {}

json OpenTab::closeTab()
{
    tab->setState(new CloseTab(tab));

    return {
        {"status", "success"},
        {"message", "Tab closed successfully"}};
}

double OpenTab::getBillTotal()
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
