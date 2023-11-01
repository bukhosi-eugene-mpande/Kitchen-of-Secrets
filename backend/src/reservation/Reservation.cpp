#include "Reservation.h"
#include "../customercare/Customer.h"
#include "Table.h"

Reservation::Reservation(std::shared_ptr<Customer> Customer,std::shared_ptr<Table> table) : customer(Customer), table(table) {

}

Reservation::~Reservation() {

}

std::shared_ptr<Customer> Reservation::getCustomer() {
    return this->customer;
}

std::shared_ptr<Table> Reservation::getTable() {
    return this->table;
}