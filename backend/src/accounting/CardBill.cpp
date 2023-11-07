#include "CardBill.h"

CardBill::CardBill(double billAmount) : BillStrategy(billAmount) {}

std::string CardBill::pay(double amount)
{
    if (amount >= billAmount)
    {
        billAmount -= amount;
        
        return "Card Payment successful";
    }
    else
    {
        return "Card Payment unsuccessful";
    }
}