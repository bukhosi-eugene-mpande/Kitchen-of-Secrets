#include "Tab.h"
#include "OpenTab.h"

Tab::Tab()
{
    state = new OpenTab();
}

void Tab::closeTab()
{
    state->closeTab();
}

double Tab::getBillTotal()
{
    return state->getBillTotal();
}

void Tab::addOrderCost(double cost)
{
    state->addOrderCost(cost);
}

void Tab::setState(TabState *newState)
{
    delete state;
    state = newState;
}
