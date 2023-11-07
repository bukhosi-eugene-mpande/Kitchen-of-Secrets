#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include "Tab.h"
#include "Billing.h"
#include "Inventory.h"

/**
 * @brief The Accounting class represents the financial management system of the restaurant.
 * 
 * This class manages the balance, tab, billing, and inventory of the restaurant.
 */
class Accounting{
    private:
        double balance;
        Tab *tab;
        Billing *billing;
        Inventory *inventory;

    public:
        /**
         * @brief Constructs a new Accounting object.
         * 
         */
        Accounting();

        /**
         * @brief Destroys the Accounting object.
         * 
         */
        ~Accounting();

        /**
         * @brief Closes the current tab and generates a bill for the customer.
         * 
         * @return std::string The bill for the customer.
         */
        std::string closeTab();

        /**
         * @brief Processes a payment for the current tab.
         * 
         * @param amount The amount of the payment.
         * @param paymentType The type of payment (e.g. cash, credit card, etc.).
         * @return std::string A confirmation message for the payment.
         */
        std::string pay(double amount, std::string paymentType);

        /**
         * @brief Gets the current balance of the restaurant.
         * 
         * @return double The current balance.
         */
        double getBalance();

};

#endif