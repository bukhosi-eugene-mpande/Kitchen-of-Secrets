#ifndef MULTIBILL_H
#define MULTIBILL_H

#include "BillStrategy.h"

class MultiBill : public BillStrategy {
    public:
        /**
         * @brief Construct a new Multi Bill object
         * 
         * @param billAmount 
         */
        MultiBill(double billAmount);

        /**
         * @brief The customers will pay depending on the their bill strategy. The customers
         * strategy is to split the bill.
         * 
         * @param amount 
         * @return json 
         */
        json pay(double amount);
};

#endif