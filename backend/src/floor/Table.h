#ifndef Table_H
#define Table_H

#include <string>
#include <vector>
#include <memory>

#include "../customercare/Customer.h"


class Table{
    private:
        int tableId;
        int tableSize;
        std::string section;
        bool isOccupied;
        bool isReserved;
        bool markedForSlit;
        bool markedForMerge;
        std::vector<std::shared_ptr<Customer>> customers;
        bool merged;
        bool split;
        
    public:
        static int tableCount;

    public:
        Table(std::string section, int tableSize);
        ~Table();
        int getTableId();
        int getTableSize();
        bool getIsOccupied();
        bool getIsReserved();
        bool getMarkedForSplit();
        bool getMarkedForMerge();
        bool getMerged();
        bool getSplit();
        std::vector<std::shared_ptr<Customer>> getCustomers();
        std::string getSection();
        void setMerged(bool merged);
        void setSplit(bool split);
        void setSection(std::string section);
        void setTableId(int tableId);
        void setTableSize(int tableSize);
        void setIsOccupied(bool isOccupied);
        void setIsReserved(bool isReserved);
        void setMarkedForSplit(bool markedForSplit);
        void setMarkedForMerge(bool markedForMerge);
        void setCustomers(std::vector<std::shared_ptr<Customer>> customers);
        void addCustomer(std::shared_ptr<Customer> customer);
        void removeCustomer(std::shared_ptr<Customer> customer);
};


#endif