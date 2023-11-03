#ifndef BILLSTRATEGY_H
#define BILLSTRATEGY_H

#include "../../json.hpp"

using json = nlohmann::json;

class BillStrategy {
    protected:
        /**
         * @brief This variable is used to store the amount of the bill.
         * 
         */
        double billAmount;

    public:
        /**
         * @brief Construct a new Bill Strategy object
         * 
         * @param billAmount 
         */
        BillStrategy(double billAmount);

        /**
         * @brief The customer(s) will pay depending on the customer's bill strategy. The customer(s)
         * can either pay via card or cash or split the bill amongst their friends or family.
         * 
         * @param amount 
         * @return json 
         */
        virtual json pay(double amount) = 0;
};

#endif