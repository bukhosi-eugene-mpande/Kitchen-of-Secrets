#ifndef TABLE_H
#define TABLE_H

#include "GameComponent.h"

#include <memory>

class Table : public GameComponent{
    private:
        int tableID;
        int xCoord;
        int yCoord;
        bool isOccupied;
    public:
        Table(Engine* engine, int tableID);
        ~Table();
        virtual int getTableID();
        virtual void setTableID(int tableID);
        virtual void placeTable(int xCoord, int yCoord);
        virtual bool getIsOccupied();
        virtual void setIsOccupied(bool isOccupied);
        virtual void sendNotification() = 0;
        virtual void receiveNotification(std::string message) = 0;
        
};

#endif