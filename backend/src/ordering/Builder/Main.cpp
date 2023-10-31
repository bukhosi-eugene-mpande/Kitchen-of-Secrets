#include "HalloweenOrderBuidler.h"
#include "Waiter.h"
#include "Management.h"
#include "Customer.h"
#include "OrderProcess.h"
#include "FoodMenuFactory.h"
#include "DrinksMenuFactory.h"

int main()
{
    
    FoodMenuFactory foodFactory;
    DrinksMenuFactory drinksFactory;

    Menu* foodMenu = foodFactory.createMenu();
    foodMenu->setItems({});
    foodMenu->displayMenu();

    Menu* drinksMenu = drinksFactory.createMenu();
    drinksMenu->setItems( {
        {"Spider Blood", 4.99},
        {"Ghost Blood", 3.99},
        {"Venom", 5.99},
        {"Bloody Mary", 6.99},
        {"Pumpkin Latte", 4.49},
        {"Witch's Brew", 5.49},
        {"Zombie Cocktail", 6.49},
        {"Poisedon", 7.99},
        {"Invisible Killer", 8.99},
        {"Scary Mocktail", 4.99}
    })
;
    drinksMenu->displayMenu();

    // Create a management object
    Management* management = new Management();

    // Create a customer object
    Customer* customer = new Customer("John Doe", "Credit Card");

    // Create a waiter object
    Waiter* waiter = new Waiter(management, customer);
    std::cout<<"I can get here"<<std::endl;
    // Create a HalloweenOrderBuilder object
    HalloweenOrderBuilder* halloweenOrderBuilder = new HalloweenOrderBuilder();

    // Set the builder for the waiter
    waiter->setBuilder(halloweenOrderBuilder);

    // The waiter takes the order
    waiter->takeOrder();
    std::cout<< "i can take  order"<<std::endl;

    // The waiter serves the order to the customer
    waiter->serveOrder(customer);
    // Create an OrderProcess (concrete visitor) object
    OrderProcess* orderProcess = new OrderProcess();

    // The waiter and customer accept the visitor
    waiter->accept(orderProcess);
    customer->accept(orderProcess);

    // Clean up
    // delete orderProcess;
    // delete halloweenOrderBuilder;
    // delete waiter;
    // delete customer;
    // delete management;
    // delete foodMenu;
    // delete drinksMenu;

    return 0;
}
