#ifndef BILLING_H
#define BILLING_H

#include "BillStrategy.h"
#include "backend/src/management/GameComponent.h"

class Billing : public GameComponent
{
private:
    std::shared_ptr<BillStrategy> billStrategy;

public:
    Billing(std::shared_ptr<Engine> engine, std::shared_ptr<BillStrategy> billStrategy);
    json pay(double amount);
};

#endif