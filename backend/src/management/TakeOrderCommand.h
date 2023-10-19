#ifndef TAKE_ORDER_COMMAND_H
#define TAKE_ORDER_COMMAND_H

#include "Command.h"
#include <vector>

/**
 * @brief 
 * 
 */
class TakeOrderCommand : public Command {
    private:
        /**
         * @brief 
         * 
         */
        std::vector<Order*> orders;

        /**
         * @brief 
         * 
         */
        Table* table;
    public:
        /**
         * @brief Construct a new Take Order Command object
         * 
         * @param orders 
         * @param table 
         */
        TakeOrderCommand(std::vector<Order*> orders, Table* table);

        /**
         * @brief Destroy the Take Order Command object
         * 
         */
        ~TakeOrderCommand();

        /**
         * @brief 
         * 
         */
        virtual void execute();
};

#endif