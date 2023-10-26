#include <iostream>

#include "Tab/Tab.h"

int main()
{
    Tab *tab = new Tab();

    std::cout << tab->addOrderCost(10) << std::endl;
    std::cout << tab->addOrderCost(20) << std::endl;
    std::cout << tab->addOrderCost(30) << std::endl;

    std::cout << tab->getBillTotal() << std::endl;

    std::cout << tab->closeTab() << std::endl;

    std::cout << tab->addOrderCost(40) << std::endl;

    return 0;
}

/*
#include <iostream>

#include "Billing/Billing.h"
#include "Billing/CashBill.h"
#include "Billing/CardBill.h"
#include "Billing/MultiBill.h"

int main()
{
    std::cout << "Accounting Says Hi" << std::endl;

    Billing *billing = new Billing(new MultiBill(100));

    std::cout << billing->pay(35) << std::endl;

    return 0;
}
*/
