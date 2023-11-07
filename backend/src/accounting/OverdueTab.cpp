#include "OverdueTab.h"

OverdueTab::OverdueTab(Tab *tab) : TabState(tab) {}

std::string OverdueTab::closeTab()
{
    return "Tab is overdue";
}

double OverdueTab::getBillTotal()
{
    double total = 0.0;

    for (double cost : orders)
    {
        total += cost;
    }

    return total;
}

std::string OverdueTab::addOrderCost(double cost)
{
    return"Tab is overdue";
}
