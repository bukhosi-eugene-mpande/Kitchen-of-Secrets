#ifndef Floor_H
#define Floor_H

#include <string>
#include <vector>
#include <memory>

#include "PrivateTable.h"
#include "GeneralTable.h"

class Floor{
    private:
        std::vector<std::shared_ptr<PrivateTable>> privateTables;
        
        std::vector<std::shared_ptr<GeneralTable>> generalTables;

    public:
        Floor();

        ~Floor();

        std::vector<std::shared_ptr<PrivateTable>> getPrivateTables();

        std::vector<std::shared_ptr<GeneralTable>> getGeneralTables();
        
        void setPrivateTables(std::vector<std::shared_ptr<PrivateTable>> privateTables);
        
        void setGeneralTables(std::vector<std::shared_ptr<GeneralTable>> generalTables);
        
        void addPrivateTable(std::shared_ptr<PrivateTable> privateTable);
        
        void addGeneralTable(std::shared_ptr<GeneralTable> generalTable);
        
        void removePrivateTable(std::shared_ptr<PrivateTable> privateTable);
        
        void removeGeneralTable(std::shared_ptr<GeneralTable> generalTable);
        
        std::vector<std::shared_ptr<Customer>> getAllCustomers();

        void mergePrivateTables(int tableId1, int tableId2);

        void mergeGeneralTables(int tableId1, int tableId2);

        void splitPrivateTable(int tableId);

        void splitGeneralTable(int tableId);

};


#endif