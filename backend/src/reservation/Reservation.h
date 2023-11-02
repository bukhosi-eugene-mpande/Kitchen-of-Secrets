#ifndef Reservation_H
#define Reservation_H

#include <string>
#include <vector>
#include <memory>

class Customer;
class Table;

class Reservation {
    std::shared_ptr<CustomerTemplate> customer;
    std::shared_ptr<Table> table;

    public:
        Reservation(std::shared_ptr<CustomerTemplate> Customer,std::shared_ptr<Table> table);
        ~Reservation();
        std::shared_ptr<CustomerTemplate> getCustomer();
        std::shared_ptr<Table> getTable();

};

#endif