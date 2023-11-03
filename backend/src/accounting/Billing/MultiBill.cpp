#include "MultiBill.h"

MultiBill::MultiBill(double billAmount) : BillStrategy(billAmount) {}

json MultiBill::pay(double amount)
{
    int numPayments = 0;
    
    while (billAmount > 0 && numPayments < 3)
    {
        billAmount -= amount;
        numPayments++;
    }

    if (billAmount <= 0)
    {
        return {
            {"status", "success"},
            {"message", "Multi Payment successful"}};
    }
    else
    {
        return {
            {"status", "error"},
            {"message", "Multi Payment failed. Insufficient funds."}};
    }
}