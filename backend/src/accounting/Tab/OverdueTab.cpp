#include "OverdueTab.h"

json OverdueTab::closeTab()
{
    return {
        {"status", "error"},
        {"message", "Tab is overdue"}};
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

json OverdueTab::addOrderCost(double cost)
{
    return {
        {"status", "error"},
        {"message", "Tab is overdue"}};
}
