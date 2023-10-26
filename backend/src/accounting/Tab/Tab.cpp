#include "Tab.h"
#include "OpenTab.h"

Tab::Tab()
{
    state = new OpenTab();
}

json Tab::closeTab()
{
    state->closeTab();
}

double Tab::getBillTotal()
{
    return state->getBillTotal();
}

json Tab::addOrderCost(double cost)
{
    state->addOrderCost(cost);
}

void Tab::setState(TabState *newState)
{
    delete state;
    state = newState;
}
