#include <iostream>

#include "Billing/Billing.h"
#include "Billing/CashBill.h"
// #include "Billing/CardBill.h"

int main()
{
    std::cout << "Accounting Says Hi" << std::endl;

    Billing *billing = new Billing(new CashBill(100));
    billing->pay(50);

    return 0;
}