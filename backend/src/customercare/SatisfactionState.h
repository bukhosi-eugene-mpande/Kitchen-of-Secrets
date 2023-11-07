#ifndef SATISFACTION_STATE_H
#define SATISFACTION_STATE_H

#include <memory>
#include <string>
#include "CustomerTemplate.h"

/**
 * @brief The SatisfactionState class represents the state of customer satisfaction.
 * 
 * This class is an abstract base class that defines the interface for all satisfaction states.
 * It contains information about the customer, discount, tip, and state name.
 */
class SatisfactionState{
    protected:
        CustomerTemplate* customer; /**< Pointer to the customer object */
        double discount; /**< Discount percentage */
        double tip; /**< Tip amount */
        std::string stateName; /**< Name of the satisfaction state */
    public:
        /**
         * @brief Constructor for SatisfactionState class.
         * 
         * @param stateName Name of the satisfaction state.
         * @param customer Pointer to the customer object.
         * @param discount Discount percentage.
         * @param tip Tip amount.
         */
        SatisfactionState(std::string stateName, CustomerTemplate* customer, double discount, double tip);

        /**
         * @brief Setter for customer object.
         * 
         * @param customer Pointer to the customer object.
         */
        void setCustomer(CustomerTemplate* customer);

        /**
         * @brief Getter for customer object.
         * 
         * @return Pointer to the customer object.
         */
        CustomerTemplate* getCustomer();

        /**
         * @brief Pure virtual function to display satisfaction state on console.
         */
        virtual void console()=0;

        /**
         * @brief Pure virtual function to handle customer anger.
         */
        virtual void anger()=0;

        /**
         * @brief Calculates the bill amount after applying discount and tip.
         * 
         * @param bill Total bill amount.
         * @return Bill amount after applying discount and tip.
         */
        double calculateBill(double bill);

        /**
         * @brief Getter for tip amount.
         * 
         * @return Tip amount.
         */
        double getTip();

        /**
         * @brief Getter for satisfaction state name.
         * 
         * @return Satisfaction state name.
         */
        std::string getStateName();
};
#endif