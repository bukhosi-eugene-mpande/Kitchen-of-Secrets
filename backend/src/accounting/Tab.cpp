#include "Tab.h"
#include "OpenTab.h"
#include "OverdueTab.h"

Tab::Tab()
{
    state = new OpenTab(this);
}

std::string Tab::closeTab()
{
    return state->closeTab();
}

double Tab::getBillTotal()
{
    return state->getBillTotal();
}

std::string Tab::addOrderCost(double cost)
{
    if (getBillTotal() > 1000)
    {
        setState(new OverdueTab(this));

        return"Tab is overdue";
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
