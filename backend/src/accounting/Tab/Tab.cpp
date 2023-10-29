#include "Tab.h"
#include "OpenTab.h"
#include "OverdueTab.h"

Tab::Tab()
{
    state = new OpenTab(this);
}

json Tab::closeTab()
{
    return state->closeTab();
}

double Tab::getBillTotal()
{
    return state->getBillTotal();
}

json Tab::addOrderCost(double cost)
{
    if (getBillTotal() > 1000)
    {
        setState(new OverdueTab(this));

        return {
            {"status", "error"},
            {"message", "Tab is overdue"}};
    }
    else
    {
        return state->addOrderCost(cost);
    }
}

void Tab::setState(TabState *newState)
{
    state = newState;
}
