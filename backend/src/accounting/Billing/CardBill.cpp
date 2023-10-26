#include "CardBill.h"

CardBill::CardBill(double billAmount) : BillStrategy(billAmount) {}

json CardBill::pay(double amount)
{
    if (amount >= billAmount)
    {
        return {
            {"status", "success"},
            {"message", "Card Payment successful"}};
    }
    else
    {
        return {
            {"status", "error"},
            {"message", "Card Payment unsuccessful"}};
    }
}