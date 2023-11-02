#include "Billing.h"

Billing::Billing(std::shared_ptr<Engine> engine, std::shared_ptr<BillStrategy> billStrategy) : GameComponent(engine)
{
    this->billStrategy = billStrategy;
}

json Billing::pay(double amount)
{
    return billStrategy->pay(amount);
}