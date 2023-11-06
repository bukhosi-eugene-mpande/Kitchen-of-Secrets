#include "MultiBill.h"

MultiBill::MultiBill(double billAmount) : BillStrategy(billAmount) {}

std::string MultiBill::pay(double amount)
{
    int numPayments = 0;
    
    while (billAmount > 0 && numPayments < 3)
    {
        billAmount -= amount;
        numPayments++;
    }

    if (billAmount <= 0)
    {
        return "Multi Payment successful";
    }
    else
    {
        return "Multi Payment failed. Insufficient funds.";
    }
}