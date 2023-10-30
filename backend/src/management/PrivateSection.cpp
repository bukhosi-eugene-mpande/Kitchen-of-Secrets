#include "PrivateSection.h"

PrivateSection::PrivateSection() {
    seat = 2;
}

PrivateSection::~PrivateSection() {}

void PrivateSection::seatCustomers(Customer* customer) {
    this->customer = customer;
}

void PrivateSection::combineTables() {}

void PrivateSection::seperateTables(Table *table1, Table *table2) {}
