#include "Reservation.h"
#include "../customercare/Customer.h"
#include "Table.h"

Reservation::Reservation(std::shared_ptr<Engine> engine, std::shared_ptr<CustomerTemplate> customer,std::shared_ptr<Table> table) : GameComponent(engine) {
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