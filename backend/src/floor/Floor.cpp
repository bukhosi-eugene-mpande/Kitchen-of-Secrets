#include "Floor.h"

Floor::Floor() {
    for (int i = 0; i < 10; i++) {
        std::shared_ptr<PrivateTable> privateTable = std::make_shared<PrivateTable>();
        this->privateTables.push_back(privateTable);
    }
    for (int i = 0; i < 10; i++) {
        std::shared_ptr<GeneralTable> generalTable = std::make_shared<GeneralTable>();
        this->generalTables.push_back(generalTable);
    }
}

Floor::~Floor() {

}

std::vector<std::shared_ptr<PrivateTable>> Floor::getPrivateTables() {
    return this->privateTables;
}

std::vector<std::shared_ptr<GeneralTable>> Floor::getGeneralTables() {
    return this->generalTables;
}

void Floor::setPrivateTables(std::vector<std::shared_ptr<PrivateTable>> privateTables) {
    this->privateTables = privateTables;
}

void Floor::setGeneralTables(std::vector<std::shared_ptr<GeneralTable>> generalTables) {
    this->generalTables = generalTables;
}

void Floor::addPrivateTable(std::shared_ptr<PrivateTable> privateTable) {
    this->privateTables.push_back(privateTable);
}

void Floor::addGeneralTable(std::shared_ptr<GeneralTable> generalTable) {
    this->generalTables.push_back(generalTable);
}

void Floor::removePrivateTable(std::shared_ptr<PrivateTable> privateTable) {
    for (int i = 0; i < this->privateTables.size(); i++) {
        if (this->privateTables[i]->getTableId() == privateTable->getTableId()) {
            this->privateTables.erase(this->privateTables.begin() + i);
        }
    }
}

void Floor::removeGeneralTable(std::shared_ptr<GeneralTable> generalTable) {
    for (int i = 0; i < this->generalTables.size(); i++) {
        if (this->generalTables[i]->getTableId() == generalTable->getTableId()) {
            this->generalTables.erase(this->generalTables.begin() + i);
        }
    }
}

std::vector<std::shared_ptr<Customer>> Floor::getAllCustomers() {
    std::vector<std::shared_ptr<Customer>> customers;
    for (int i = 0; i < this->privateTables.size(); i++) {
        for (int j = 0; j < this->privateTables[i]->getCustomers().size(); j++) {
            customers.push_back(this->privateTables[i]->getCustomers()[j]);
        }
    }
    for (int i = 0; i < this->generalTables.size(); i++) {
        for (int j = 0; j < this->generalTables[i]->getCustomers().size(); j++) {
            customers.push_back(this->generalTables[i]->getCustomers()[j]);
        }
    }
    return customers;
}

void Floor::mergePrivateTables(int tableId1, int tableId2) {
    std::shared_ptr<PrivateTable> table1;
    std::shared_ptr<PrivateTable> table2;
    for (int i = 0; i < this->privateTables.size(); i++) {
        if (this->privateTables[i]->getTableId() == tableId1) {
            table1 = this->privateTables[i];
        }
        if (this->privateTables[i]->getTableId() == tableId2) {
            table2 = this->privateTables[i];
        }
    }
    if(table1 != nullptr && table2 != nullptr) {
        if(table1->getMarkedForMerge() && table2->getMarkedForMerge()){
            table1->setTableSize(table1->getTableSize() + table2->getTableSize());
            table1->setMarkedForMerge(false);
            table1->setMerged(true);
            this->removePrivateTable(table2);
        }
    }
}

void Floor::mergeGeneralTables(int tableId1, int tableId2) {
    std::shared_ptr<GeneralTable> table1;
    std::shared_ptr<GeneralTable> table2;
    for (int i = 0; i < this->generalTables.size(); i++) {
        if (this->generalTables[i]->getTableId() == tableId1) {
            table1 = this->generalTables[i];
        }
        if (this->generalTables[i]->getTableId() == tableId2) {
            table2 = this->generalTables[i];
        }
    }
    if(table1 != nullptr && table2 != nullptr) {
        if(table1->getMarkedForMerge() && table2->getMarkedForMerge()){
            table1->setTableSize(table1->getTableSize() + table2->getTableSize());
            table1->setMarkedForMerge(false);
            table1->setMerged(true);
            this->removeGeneralTable(table2);
        }
    }
}

void Floor::splitPrivateTable(int tableId) {
    std::shared_ptr<PrivateTable> table;
    for (int i = 0; i < this->privateTables.size(); i++) {
        if (this->privateTables[i]->getTableId() == tableId) {
            table = this->privateTables[i];
        }
    }
    if(table != nullptr) {
        if(table->getMarkedForSplit()){
            std::shared_ptr<PrivateTable> newTable = std::make_shared<PrivateTable>();
            newTable->setTableSize(table->getTableSize() / 2);
            table->setTableSize(table->getTableSize() / 2);
            newTable->setMarkedForSplit(false);
            newTable->setSplit(true);
            this->addPrivateTable(newTable);
        }
    }
}

void Floor::splitGeneralTable(int tableId) {
    std::shared_ptr<GeneralTable> table;
    for (int i = 0; i < this->generalTables.size(); i++) {
        if (this->generalTables[i]->getTableId() == tableId) {
            table = this->generalTables[i];
        }
    }
    if(table != nullptr) {
        if(table->getMarkedForSplit()){
            std::shared_ptr<GeneralTable> newTable = std::make_shared<GeneralTable>();
            newTable->setTableSize(table->getTableSize() / 2);
            table->setTableSize(table->getTableSize() / 2);
            newTable->setMarkedForSplit(false);
            newTable->setSplit(true);
            this->addGeneralTable(newTable);
        }
    }
}