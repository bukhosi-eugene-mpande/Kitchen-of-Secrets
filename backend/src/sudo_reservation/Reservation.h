#ifndef RESERVATION_H
#define RESERVATION_H

#include "backend/src/management/GameComponent.h"

#include <string>
#include <vector>
#include <memory>

class Customer;
class Table;

class Reservation : public GameComponent {
    std::shared_ptr<CustomerTemplate> customer;
    std::shared_ptr<Table> table;

    public:
        Reservation(std::shared_ptr<Engine> engine, std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);
        ~Reservation();
        std::shared_ptr<CustomerTemplate> getCustomer();
        std::shared_ptr<Table> getTable();

};

#endif