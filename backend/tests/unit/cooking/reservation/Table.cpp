#include "Table.h"
#include "../customercare/Customer.h"

Table::Table(std::string section,int capacity) {
    this->tableCount++;
    this->section = section;
    this->capacity = capacity;
    this->tableId = this->tableCount;
    this->reserved = false;
    this->occupied = false;
}

Table::~Table() {
    this->tableCount--;
}

void Table::addOccupant(std::shared_ptr<Customer> occupant) {
    this->occupants.push_back(occupant);
}

std::vector<std::shared_ptr<Customer>> Table::getOccupants() {
    return this->occupants;
}

void Table::removeOccupant(std::shared_ptr<Customer> occupant) {
    for (int i = 0; i < this->occupants.size(); i++) {
        if (this->occupants[i] == occupant) {
            this->occupants.erase(this->occupants.begin() + i);
        }
    }
}

int Table::getTableId() {
    return this->tableId;
}

void Table::setTableId(int tableId) {
    this->tableId = tableId;
}

int Table::getCapacity() {
    return this->capacity;
}

void Table::setCapacity(int capacity) {
    this->capacity = capacity;
}

bool Table::isFull() {
    return this->occupants.size() == this->capacity;
}

bool Table::isEmpty() {
    return this->occupants.size() == 0;
}

int Table::getOccupantCount() {
    return this->occupants.size();
}

bool Table::isReserved() {
    return this->reserved;
}

void Table::setReserved(bool reserved) {
    this->reserved = reserved;
}

bool Table::isOccupied() {
    return this->occupied;
}

void Table::setOccupied(bool occupied) {
    this->occupied = occupied;
}

std::string Table::getSection() {
    return this->section;
}

void Table::setSection(std::string section) {
    this->section = section;
}

int Table::tableCount = 0;
