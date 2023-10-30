#ifndef TABLE_H
#define TABLE_H

#include <iostream>

using namespace std;

class Table {
protected:
    int tableID;
public:
    Table(int tableID);
    ~Table();
    virtual void addReservation() = 0;
    virtual void markTableOccupied() = 0;
    virtual bool isTableAvailable() = 0;
    int getTableID();
    void setTableID(int tableID);
};

#endif