#ifndef ACCOUNTING_H
#define ACCOUNTING_H

#include "Tab/Tab.h"
#include "Billing/Billing.h"

#include <memory>

class Accounting : public GameComponent{
    private:
        double balance;
    public:
        Accounting(std::shared_ptr<Engine> engine);
        ~Accounting();
        double getBalance();
        void setBalance(double balance);
        json closeTab();
        json pay(double amount, std::string paymentType);
        /**
         * @brief 
         * 
         */
        virtual void sendEvent();

        /**
         * @brief 
         * 
         * @param event 
         */
        virtual void receiveEvent(std::string event);
};

#endif