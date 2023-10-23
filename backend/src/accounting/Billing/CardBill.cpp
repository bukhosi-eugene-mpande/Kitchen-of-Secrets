#include "CardBill.h"

CardBill::CardBill(double billAmount) : BillStrategy(billAmount) {}

void CardBill::pay(double amount)
{
    billAmount -= amount;
}