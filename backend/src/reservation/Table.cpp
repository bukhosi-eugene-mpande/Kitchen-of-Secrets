#include "Table.h"

int Table::tableCount = 0;

Table::Table(std::string section, int tableSize){
    this->section = section;
    this->tableId = ++tableCount;
    this->tableSize = tableSize;
    this->isOccupied = false;
    this->isReserved = false;
    this->markedForSlit = false;
    this->markedForMerge = false;
    this->merged = false;
    this->split = false;
}

Table::~Table(){
    tableCount--;
}

int Table::getTableId(){
    return this->tableId;
}

int Table::getTableSize(){
    return this->tableSize;
}

bool Table::getIsOccupied(){
    return this->isOccupied;
}

bool Table::getIsReserved(){
    return this->isReserved;
}

bool Table::getMarkedForSplit(){
    return this->markedForSlit;
}


bool Table::getMarkedForMerge(){
    return this->markedForMerge;
}

std::vector<std::shared_ptr<Customer>> Table::getCustomers(){
    return this->customers;
}

std::string Table::getSection(){
    return this->section;
}

bool Table::getMerged(){
    return this->merged;
}

bool Table::getSplit(){
    return this->split;
}

void Table::setMerged(bool merged){
    this->merged = merged;
}

void Table::setSplit(bool split){
    this->split = split;
}

void Table::setSection(std::string section){
    this->section = section;
}

void Table::setTableId(int tableId){
    this->tableId = tableId;
}

void Table::setTableSize(int tableSize){
    this->tableSize = tableSize;
}

void Table::setIsOccupied(bool isOccupied){
    this->isOccupied = isOccupied;
}

void Table::setIsReserved(bool isReserved){
    this->isReserved = isReserved;
}

void Table::setMarkedForSplit(bool markedForSplit){
    this->markedForSlit = markedForSplit;
}

void Table::setMarkedForMerge(bool markedForMerge){
    this->markedForMerge = markedForMerge;
}

void Table::setCustomers(std::vector<std::shared_ptr<Customer>> customers){
    this->customers = customers;
}

void Table::addCustomer(std::shared_ptr<Customer> customer){
    this->customers.push_back(customer);
}

void Table::removeCustomer(std::shared_ptr<Customer> customer){
    auto it = std::find(this->customers.begin(), this->customers.end(), customer);
    if (it != this->customers.end()) {
        this->customers.erase(it);
    }
}

void Table::clear(){
    this->customers.clear();
    this->isOccupied = false;
    this->isReserved = false;
    this->markedForSlit = false;
    this->markedForMerge = false;
    this->merged = false;
    this->split = false;
}
