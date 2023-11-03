#ifndef CARD_BILL_H
#define CARD_BILL_H

#include "BillStrategy.h"

class CardBill : public BillStrategy {
    public:
        /**
         * @brief Construct a new Card Bill object
         * 
         * @param billAmount 
         */
        CardBill(double billAmount);

        /**
         * @brief The customer(s) will pay depending on the customer's bill strategy. The customer(s)
         * strategy is to pay via card.
         * 
         * @param amount 
         * @return json 
         */
        json pay(double amount);
};

#endif