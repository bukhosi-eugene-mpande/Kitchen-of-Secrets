#include "Reservation.h"
#include "Table.h"
#include "../customercare/CustomerTemplate.h"

Reservation::Reservation(std::shared_ptr<CustomerTemplate> customer,std::shared_ptr<Table> table){
    this->customer = customer;
    this->table = table;
}

Reservation::~Reservation() {}

std::shared_ptr<CustomerTemplate> Reservation::getCustomer() {
    return this->customer;
}

std::shared_ptr<Table> Reservation::getTable() {
    return this->table;
}