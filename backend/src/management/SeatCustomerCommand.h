#ifndef SEAT_CUSTOMER_COMMAND_H
#define SEAT_CUSTOMER_COMMAND_H

#include "Command.h"

class SeatCustomerCommand : public Command {
    private:
        /**
         * @brief 
         * 
         */
        std::vector<Customer*> customers;

        /**
         * @brief 
         * 
         */
        Table* table;
    public:
        /**
         * @brief Construct a new Seat Customer Command object
         * 
         * @param customers 
         * @param table 
         */
        SeatCustomerCommand(std::vector<Customer*> customers, Table* table);

        /**
         * @brief Destroy the Seat Customer Command object
         * 
         */
        ~SeatCustomerCommand();

        /**
         * @brief 
         * 
         */
        virtual void execute();
};

#endif