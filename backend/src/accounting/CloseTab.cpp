#include "CloseTab.h"

CloseTab::CloseTab(Tab *tab) : TabState(tab) {}

std::string CloseTab::closeTab()
{
    return "Tab is closed";
}

double CloseTab::getBillTotal()
{
    double total = 0.0;

    for (double cost : orders)
    {
        total += cost;
    }

    return total;
}

std::string CloseTab::addOrderCost(double cost)
{
    return "Tab is closed";
}