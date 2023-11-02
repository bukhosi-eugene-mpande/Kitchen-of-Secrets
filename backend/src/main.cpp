#include <iostream>

#include "../tests/includes/customercare_all.cpp"
#include "../tests/includes/reservation_all.cpp"
#include "../tests/includes/inventory_all.cpp"
#include "../tests/includes/ordering_all.cpp"
#include "../tests/includes/cooking_all.cpp"
#include "../tests/includes/management_all.cpp"

int main() {

    std::shared_ptr<Management> management = std::make_shared<Management>();
    Customer*  customer = new Customer(management);
    customer->setManagement(management);

    customer->requestReservation();
     
    return 0;
}
