#include "CashBill.h"

CashBill::CashBill(double billAmount) : BillStrategy(billAmount) {}

void CashBill::pay(double amount)
{
    billAmount -= amount;
}