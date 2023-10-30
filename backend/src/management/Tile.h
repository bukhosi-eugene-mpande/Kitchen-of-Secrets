#ifndef TILE_H
#define TILE_H

#include <memory>

class Table;

class Tile {
    private:
        int xCoord;
        int yCoord;
        Tile* up;
        Tile* down;
        Tile* left;
        Tile* right;
        Table* table;
    public:
        Tile(int xCoord, int yCoord);
        ~Tile();
        int getXCoord();
        void setXCoord(int newXCoord);
        int getYCoord();
        void setYCoord(int newYCoord);
        Tile* getUp();
        void setUp(Tile* newUp);
        Tile* getDown();
        void setDown(Tile* newDown);
        Tile* getLeft();
        void setLeft(Tile* newLeft);
        Tile* getRight();
        void setRight(Tile* newRight);
        Table* getTable();
        void setTable(Table* table);
};

#endif

