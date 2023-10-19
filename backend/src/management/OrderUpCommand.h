#ifndef ORDER_UP_COMMAND_H
#define ORDER_UP_COMMAND_H

#include "Command.h"

#include <vector>

class OrderUpCommand : public Command {
    private:
        /**
         * @brief 
         * 
         */
        std::vector<Order*> orders

        /**
         * @brief 
         * 
         */
        Table* table;
    public:
        /**
         * @brief Construct a new Order Up Command object
         * 
         * @param orders 
         * @param table 
         */
        OrderUpCommand(std::vector<Order*> orders, Table* table);

        /**
         * @brief Destroy the Order Up Command object
         * 
         */
        ~OrderUpCommand();

        /**
         * @brief 
         * 
         */
        virtual void execute();

};

#endif