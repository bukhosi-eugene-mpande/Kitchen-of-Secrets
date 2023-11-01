#ifndef Section_H
#define Section_H

#include <string>
#include <vector>
#include <memory>

#include "Table.h"
#include "../customercare/Customer.h"

class Section{

    private:
        std::string name;
        int capacity;
        std::vector<std::shared_ptr<Table>> tables;
        
    public:
        Section(std::string name,int capacity);

        ~Section();

        std::vector<std::shared_ptr<Table>> getTables();
        
        void setTables(std::vector<std::shared_ptr<Table>> tables);

        void addTable(std::shared_ptr<Table> table);

        void removeTable(std::shared_ptr<Table> Table);
        
        std::vector<std::shared_ptr<Customer>> getAllCustomers();

        void mergeTables(int tableId1, int tableId2);

        void splitTable(int tableId);

};

#endif