#include "Reservation.h"

Reservation::Reservation() {
    this->tableId = 0;
    this->customerId = 0;
}

Reservation::~Reservation() {
}

int Reservation::getTableId() {
    return this->tableId;
}

void Reservation::setTableId(int tableId) {
    this->tableId = tableId;
}

int Reservation::getCustomerId() {
    return this->customerId;
}

void Reservation::setCustomerId(int customerId) {
    this->customerId = customerId;
}
