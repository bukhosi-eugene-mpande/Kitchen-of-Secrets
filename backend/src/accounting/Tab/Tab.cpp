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

double Tab::getTabTotal()
{
    return 0.0;
}

double Tab::getTabTotal()
{
    return state->getTabTotal();
}

json Tab::addOrderCost(double cost)
{
    if (getTabTotal() > 1000)
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

double Tab::calculateOrderCost(const std::vector<std::shared_ptr<Order>> orderedItems)
{
    double orderCost = 0.00;
    for (std::shared_ptr<Order> order : orderedItems) {
        orderCost += order->getPrice();
    }
    return orderCost;
}

std::vector<std::shared_ptr<Order>> Tab::getOrderedItems() {
    return orderedItems;
}

void Tab::sendEvent() {}

void Tab::receiveEvent(std::string event)
{
    if (event == "Add Order Cost") {
        double cost = calculateOrderCost(orderedItems);
        addOrderCost(cost);
    }
    if (event == "Close Tab") {
        closeTab();
    }
}
