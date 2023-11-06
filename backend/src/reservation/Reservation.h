#ifndef Reservation_H
#define Reservation_H

#include <string>
#include <vector>
#include <memory>

class CustomerTemplate;
class Table;

class Reservation {
    private:
    std::shared_ptr<CustomerTemplate> customer;
    std::shared_ptr<Table> table;

    public:
        Reservation(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);
        ~Reservation();
        std::shared_ptr<CustomerTemplate> getCustomer();
        std::shared_ptr<Table> getTable();

};

#endif