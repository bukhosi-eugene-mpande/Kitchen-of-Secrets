#ifndef Customer_H
#define Customer_H

#include <iostream>
#include <vector>

#include "SatisfactionState.h"
#include <memory>
class Customer {
    private:
        std::vector<std::shared_ptr<Customer>> guests;
        std::shared_ptr<SatisfactionState> mood;
        int customerId;

    public:
        Customer();
        ~Customer();
        void addGuest(std::shared_ptr<Customer> guest);
        std::vector<std::shared_ptr<Customer>> getGuests();
        void removeGuest(std::shared_ptr<Customer> guest);
        void changeMood(std::shared_ptr<SatisfactionState> mood);
        double calculateTip(double bill);

};

#endif