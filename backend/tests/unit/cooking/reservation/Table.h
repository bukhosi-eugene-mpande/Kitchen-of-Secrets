#ifndef Table_H
#define Table_H

#include <iostream>
#include <vector>

#include <memory>
class Customer;

class Table {
    private:
        std::vector<std::shared_ptr<Customer>> occupants;
        std::string section;
        bool reserved;
        bool occupied;
        int tableId;
        int capacity;
        static int tableCount;

    public:
        Table(std::string section,int capacity);
        ~Table();
        void addOccupant(std::shared_ptr<Customer> occupant);
        std::vector<std::shared_ptr<Customer>> getOccupants();
        void removeOccupant(std::shared_ptr<Customer> occupant);
        int getTableId();
        void setTableId(int tableId);
        int getCapacity();
        void setCapacity(int capacity);
        bool isFull();
        bool isEmpty();
        int getOccupantCount();
        bool isReserved();
        void setReserved(bool reserved);
        bool isOccupied();
        void setOccupied(bool occupied);
        std::string getSection();
        void setSection(std::string section);

};

#endif