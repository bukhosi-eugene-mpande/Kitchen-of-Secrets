#include "Waiter.h"
#include "OrderBuilder.h"
#include "HalloweenOrderBuidler.h"

int main() {
    Waiter waiter;
    HalloweenOrderBuilder halloween_builder;

    waiter.setBuilder(&halloween_builder);
    Order* order = waiter.takeOrder();

    std::cout << "Your order:\n";
    order->listItems();

    delete order;
    
    return 0;
}