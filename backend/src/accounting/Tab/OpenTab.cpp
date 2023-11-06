#include "OpenTab.h"
#include "Tab.h"
#include "CloseTab.h"

OpenTab::OpenTab(Tab *tab) : TabState(tab) {}

std::string OpenTab::closeTab()
{
    tab->setState(new CloseTab(tab));

    return "Tab closed successfully";
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

std::string OpenTab::addOrderCost(double cost)
{
    orders.push_back(cost);

    return "Order added successfully";
}
