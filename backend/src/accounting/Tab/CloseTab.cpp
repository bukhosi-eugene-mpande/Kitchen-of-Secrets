#include "CloseTab.h"

CloseTab::CloseTab(Tab *tab) : TabState(tab) {}

json CloseTab::closeTab()
{
    return {
        {"status", "error"},
        {"message", "Tab is closed"}};
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

json CloseTab::addOrderCost(double cost)
{
    return {
        {"status", "error"},
        {"message", "Tab is closed"}};
}