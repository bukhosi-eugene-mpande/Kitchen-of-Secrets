#include <iostream>

#include "Inventory/FoodInventory.h"
#include "Inventory/BeverageInventory.h"

int main()
{
    Inventory *foodInventory = new FoodInventory();
    Inventory *beverageInventory = new BeverageInventory();

    std::unordered_map<std::string, int> foodItems;
    foodItems["Burger"] = 1;
    foodItems["Fries"] = 2;
    foodItems["Salad"] = 3;

    std::unordered_map<std::string, int> beverageItems;
    beverageItems["Soda"] = 1;
    beverageItems["Tea"] = 2;
    beverageItems["Coffee"] = 3;

    foodInventory->update(foodItems);
    beverageInventory->update(beverageItems);

    return 0;
}

/*
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
*/

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
