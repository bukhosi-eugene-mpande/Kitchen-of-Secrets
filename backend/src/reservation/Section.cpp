#include "Section.h"
#include "Table.h"
#include "../customercare/Customer.h"

Section::Section(std::string name,int capacity){
    this->name = name;
    this->capacity = capacity;
}

Section::~Section() {

}

std::vector<std::shared_ptr<Table>> Section::getTables() {
    return this->tables;
}

void Section::setTables(std::vector<std::shared_ptr<Table>> tables) {
    this->tables = tables;
}

void Section::addTable(std::shared_ptr<Table> table) {
    this->tables.push_back(table);
}

void Section::removeTable(std::shared_ptr<Table> Table) {
    for (int i = 0; i < (int) this->tables.size(); i++) {
        if (this->tables[i]->getTableId() == Table->getTableId()) {
            this->tables.erase(this->tables.begin() + i);
        }
    }
}

std::vector<std::shared_ptr<CustomerTemplate>> Section::getAllCustomers() {
    std::vector<std::shared_ptr<CustomerTemplate>> customers;
    for (int i = 0; i < (int) this->tables.size(); i++) {
        for (int j = 0; j < (int) this->tables[i]->getCustomers().size(); j++) {
            customers.push_back(this->tables[i]->getCustomers()[j]);
        }
    }
    return customers;
}

void Section::mergeTables(int tableId1, int tableId2) {
    std::shared_ptr<Table> table1;
    std::shared_ptr<Table> table2;
    for (int i = 0; i < (int) this->tables.size(); i++) {
        if (this->tables[i]->getTableId() == tableId1) {
            table1 = this->tables[i];
        }
        if (this->tables[i]->getTableId() == tableId2) {
            table2 = this->tables[i];
        }
    }
    if(table1 != nullptr && table2 != nullptr) {
        if(table1->getMarkedForMerge() && table2->getMarkedForMerge()){
            table1->setTableSize(table1->getTableSize() + table2->getTableSize());
            table1->setMarkedForMerge(false);
            table1->setMerged(true);
            this->removeTable(table2);
        }
    }
}

void Section::splitTable(int tableId) {
    std::shared_ptr<Table> table;
    for (int i = 0; i < (int) this->tables.size(); i++) {
        if (this->tables[i]->getTableId() == tableId) {
            table = this->tables[i];
        }
    }
    if(table != nullptr) {
        if(table->getMarkedForSplit()){
            std::shared_ptr<Table> newTable;
            if(this->name == "Private Section"){
                newTable = std::make_shared<PrivateTable>();
            }else{
                newTable = std::make_shared<GeneralTable>();
            }
            newTable->setTableSize(table->getTableSize() / 2);
            table->setTableSize(table->getTableSize() / 2);
            newTable->setMarkedForSplit(false);
            newTable->setSplit(true);
            this->addTable(newTable);
        }
    }
}

