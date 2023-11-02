#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include "backend/src/accounting/AccountingSystem.h"
#include "backend/src/customercare/Customer.h"
#include "backend/src/customercare/CustomerCareSystem.h"
#include "GameComponent.h"


#include <vector>
#include <queue>
#include <memory>

class PlayerInteraction : public GameComponent {
    private:
        std::shared_ptr<AccountingSystem> accountingSystem;
        std::shared_ptr<CustomerCareSystem> customerCareSystem;
    public:
        PlayerInteraction(std::shared_ptr<Engine> engine, std::shared_ptr<AccountingSystem> accountingSystem, std::shared_ptr<CustomerCareSystem> customerCareSystem;);
        ~PlayerInteraction();
        void cardPayment(std::shared_ptr<Customer> customer);
        void cashPayment(std::shared_ptr<Customer> customer);
        void multiplePayments(std::vector<std::shared_ptr<Customer>> customers);
        void addToTab(std::vector<std::shared_ptr<Customer>> customers);
        void closeTab(std::vector<std::shared_ptr<Customer>> customers);
        void updateInventory();
        void takeOrder();
        void orderUp();
        void seatCustomers(std::vector<Customer*>);
};

#endif