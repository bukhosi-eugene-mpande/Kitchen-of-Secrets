#ifndef PAYMENT_COMMAND_H
#define PAYMENT_COMMAND_H

#include "Command.h"

class PaymentCommand : public Command {
    private:
        /**
         * @brief 
         * 
         */
        Tab* tab;

        /**
         * @brief 
         * 
         */
        Billing* billing;

        /**
         * @brief 
         * 
         */
        Bank* bank;
    public:
        /**
         * @brief Construct a new Payment Command object
         * 
         * @param tab 
         * @param billing 
         * @param bank 
         */
        PaymentCommand(Tab* tab, Billing* billing, Bank* bank);
        
        /**
         * @brief Destroy the Payment Command object
         * 
         */
        ~PaymentCommand();

        /**
         * @brief 
         * 
         */
        virtual void execute();
};

#endif