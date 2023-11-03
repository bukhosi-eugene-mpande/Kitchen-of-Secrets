#ifndef BILLING_H
#define BILLING_H

#include "BillStrategy.h"
#include "backend/src/management/GameComponent.h"

class Billing : public GameComponent
{
private:
    std::shared_ptr<BillStrategy> billStrategy;
    double amount;
public:
    Billing(std::shared_ptr<Engine> engine, std::shared_ptr<BillStrategy> billStrategy);
    double getAmount();
    void setAmount(double amount);
    json pay(double amount);
    virtual void sendEvent();
    virtual void receiveEvent(std::string event);
};

#endif