#include "CashBill.h"

CashBill::CashBill(double billAmount) : BillStrategy(billAmount) {}

json CashBill::pay(double amount)
{
    if (amount >= billAmount)
    {
        return {
            {"status", "success"},
            {"message", "Cash Payment successful"}};
    }
    else
    {
        return {
            {"status", "error"},
            {"message", "Cash Payment unsuccessful"}};
    }
}