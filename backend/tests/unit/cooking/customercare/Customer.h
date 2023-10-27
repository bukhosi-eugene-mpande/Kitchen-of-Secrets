#ifndef Customer_H
#define Customer_H

#include <iostream>
#include <vector>

#include "SatisfactionState.h"

class Customer {
    private:
        std::vector<Customer*> guests;
        SatisfactionState* mood;

    public:
        Customer();
        ~Customer();
        void addGuest(Customer* guest);
        std::vector<Customer*> getGuests();
        void removeGuest(Customer* guest);
        void changeMood(SatisfactionState* state);
        double calculateTip(double bill);

};

#endif