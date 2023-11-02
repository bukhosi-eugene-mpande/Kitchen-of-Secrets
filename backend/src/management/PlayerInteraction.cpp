#include "PlayerInteraction.h"

// PlayerInteraction::PlayerInteraction(Engine*, AccountingSystem* accountingSystem, KitchenSystem* cookingSystem, CustomerCareSystem* customerCareSystem, OrderSystem* orderingSystem, ReservationSystem* reservationSystem) : GameComponent(engine) {
//     this->accountingSystem = accountingSystem;
//     this->cookingSystem = cookingSystem;
//     this->customerCareSystem = customerCareSystem;
//     this->orderingSystem = orderingSystem;
//     this->reservationSystem = reservationSystem;
// }

PlayerInteraction::PlayerInteraction(std::shared_ptr<Engine> engine, std::shared_ptr<AccountingSystem> accountingSystem, std::shared_ptr<CustomerCareSystem> customerCareSystem) : GameComponent(engine) {
    this->accountingSystem = accountingSystem;
    this->customerCareSystem = customerCareSystem;
}

PlayerInteraction::~PlayerInteraction() {}

void PlayerInteraction::cardPayment(std::shared_ptr<Customer> customer) {
    accountingSystem->getBilling()->pay(customer->getTotalBill());
}

void cashPayment(std::shared_ptr<Customer> customer) {
    accountingSystem->getBilling()->pay(customer->getTotalBill());
}

void multiplePayments(std::vector<std::shared_ptr<Customer>> customers) {
    std::vector<Customer>::iterator index = customers.begin();
    for (index, index < customers.end(), index++) {
        customers.at(index)
    }
}

// void PlayerInteraction::payment(Customer* customer) {
//     if (customer->wantsToOpenTab() && customer->openTab == false) {
//         accountingSystem->openTab();
//         accountingSystem->addOrderCost();
//     }
//     else if (customer->openTab()) {
//         accountingSystem->addOrderCost();
//     }
//     else if (customer->wantsToBeBilled()) {
//         accountingSystem->billCustomer();
//     }
// }

// void PlayerInteraction::updateInventory() {
//     accountingSystem->buyInventory();
// }

// void PlayerInteraction::takeOrder()
// {
//     orderingSystem->takeOrder();
//     orderingSystem->giveOrderToChef();
// }

// void PlayerInteraction::orderUp()
// {
//     cookingSystem->giveFoodToWaiter();
//     orderingSystem->giveFoodToCustomer();
// }

// void PlayerInteraction::seatCustomers(std::vector<Customer*> customers) {
//     reservationSystem->getReceptionist()->showCustomerToTable();
// }


