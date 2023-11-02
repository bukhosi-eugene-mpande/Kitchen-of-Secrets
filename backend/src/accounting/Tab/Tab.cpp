#include "Tab.h"
#include "OpenTab.h"
#include "OverdueTab.h"

Tab::Tab(std::shared_ptr<Engine> engine) : GameComponent(engine)
{
    state = std::make_shared<OpenTab>(this);
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
        setState(std::make_shared<OpenTab>(this));

        return {
            {"status", "error"},
            {"message", "Tab is overdue"}};
    }
    else
    {
        return state->addOrderCost(cost);
    }
}

void Tab::setState(std::shared_ptr<TabState> state)
{
    this->state = state;
}
