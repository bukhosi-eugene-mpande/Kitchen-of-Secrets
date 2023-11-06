#include <iostream>

#include "../tests/includes/customercare_all.cpp"
#include "../tests/includes/reservation_all.cpp"
#include "../tests/includes/inventory_all.cpp"
#include "../tests/includes/ordering_all.cpp"
#include "../tests/includes/cooking_all.cpp"
#include "../tests/includes/management_all.cpp"

int main() {
    std::shared_ptr<Management> management = std::make_shared<Management>();
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());
    management->setKitchen(kitchen);
    Section* section = management->getGeneralSection().get();
    std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(section, management.get());

    Customer*  customer1 = new Customer(management);

    CustomerNPC* customer3 = new CustomerNPC(management,true,"General Section");

    //seting up the main customer
    customer1->setManagement(management);
    customer1->setDesiredSection("General Section");
    customer1->requestReservation();
    customer1->requestToBeSeated();

    //seting up the NPC customer
    customer3->setManagement(management);
    customer3->requestReservation();
    customer3->requestToBeSeated();
    
    //SEETING UP DRINKS ORDER
    customer1->setBeverageOrder({{"Witches' Brew Punch",1},{"Vampire's Kiss Martini",2}});

    //seting up food order
    customer1->setFoodOrder({{"Vampire Garlic Bread",5},{"Werewolf Bites",4},{"Screaming Salad",3},{"Cursed Cauldron Curry",2}});
    
    //waiter going on rounds
    waiterPtr->doOrderRounds();

    //seting payment
    waiterPtr->serveBill();
    
    return 0;
}
