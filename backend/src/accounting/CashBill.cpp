#include "CashBill.h"

CashBill::CashBill(double billAmount) : BillStrategy(billAmount) {}

std::string CashBill::pay(double amount)
{
    if (amount >= billAmount)
    {
        billAmount -= amount;

        return "Cash Payment successful";
    }
    else
    {
        return "Cash Payment unsuccessful";
    }
}