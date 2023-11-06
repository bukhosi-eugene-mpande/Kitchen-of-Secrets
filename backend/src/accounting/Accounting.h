/**
 * @file Accounting.h
 * @brief Contains the declaration of the Accounting class.
 */
#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include "Tab.h"
#include "Billing.h"
#include "Inventory.h"

/**
 * @class Accounting
 * @brief Manages financial transactions, tabs, billing, and inventory.
 */

class Accounting{
   
    private:
         double balance; ///< The current balance of the accounting system.
    Tab *tab; ///< A pointer to the active tab.
    Billing *billing; ///< A pointer to the billing system.
    Inventory *inventory; ///< A pointer to the inventory system.

    public:    /**
     * @brief Constructor for the Accounting class.
     */
    Accounting();

    /**
     * @brief Destructor for the Accounting class.
     */
    ~Accounting();

    /**
     * @brief Close the active tab and generate a bill.
     * @return A string indicating the result of closing the tab.
     */
    std::string closeTab();

    /**
     * @brief Make a payment to settle the account.
     * @param amount The amount to be paid.
     * @param paymentType The type of payment (e.g., cash, credit).
     * @return A string indicating the result of the payment.
     */
    std::string pay(double amount, std::string paymentType);

    /**
     * @brief Get the current balance of the accounting system.
     * @return The current balance.
     */
    double getBalance();

};

#endif