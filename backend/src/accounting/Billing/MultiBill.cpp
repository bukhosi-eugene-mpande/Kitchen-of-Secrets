#include "MultiBill.h"

MultiBill::MultiBill(double billAmount) : BillStrategy(billAmount) {}

void MultiBill::pay(double amount)
{
    billAmount -= amount;
}