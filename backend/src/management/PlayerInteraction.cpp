#include "PlayerInteraction.h"

PlayerInteraction::PlayerInteraction(Engine*, AccountingSystem* accountingSystem, KitchenSystem* cookingSystem, CustomerCareSystem* customerCareSystem, OrderSystem* orderingSystem, ReservationSystem* reservationSystem) : GameComponent(engine) {
    this->accountingSystem = accountingSystem;
    this->cookingSystem = cookingSystem;
    this->customerCareSystem = customerCareSystem;
    this->orderingSystem = orderingSystem;
    this->reservationSystem = reservationSystem;
}

PlayerInteraction::~PlayerInteraction() {}

void PlayerInteraction::payment(Customer* customer) {
    if (customer->wantsToOpenTab() && customer->openTab == false) {
        accountingSystem->openTab();
        accountingSystem->addOrderCost();
    }
    else if (customer->openTab()) {
        accountingSystem->addOrderCost();
    }
    else if (customer->wantsToBeBilled()) {
        accountingSystem->billCustomer();
    }
}

void PlayerInteraction::updateInventory() {
    accountingSystem->buyInventory();
}

void PlayerInteraction::takeOrder()
{
    orderingSystem->takeOrder();
    orderingSystem->giveOrderToChef();
}

void PlayerInteraction::orderUp()
{
    cookingSystem->giveFoodToWaiter();
    orderingSystem->giveFoodToCustomer();
}

void PlayerInteraction::seatCustomers(std::vector<Customer*> customers) {
    reservationSystem->getReceptionist()->showCustomerToTable();
}

