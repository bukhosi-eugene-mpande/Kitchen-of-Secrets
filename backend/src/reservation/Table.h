#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <memory>

#include "GameComponent.h"
#include "ReservationSystem.h"

using namespace std; 

class Table : public GameComponent {
protected:
    int tableID;
    int xCoord;
    int yCoord;
    bool isOccupied;
    ReservationSystem* reservation;
    
public:
    Table(Engine* engine, int tableID);
    ~Table();
    int getTableID();
    void setTableID(int tableID);
    virtual void addReservation() = 0;
    virtual void placeTable(int xCoord, int yCoord);
    virtual bool getIsOccupied();
    virtual void setIsOccupied(bool isOccupied);
    virtual void sendNotification() = 0;
    virtual void receiveNotification(std::string message) = 0;
};

#endif
