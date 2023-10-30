#ifndef RESTURANT_H
#define RESTURANT_H

#include "Tile.h"
#include "Table.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <memory>

class ResturantIterator;

class Resturant {
    public:
        Resturant();
        virtual ~Resturant();
        virtual ResturantIterator* createIterator(Tile* startingTile) = 0;
        virtual Resturant& addEdge(Tile* source, Tile* destination) = 0;
        virtual std::set<Tile*> getNeighbours(Tile* tile) = 0;
        virtual bool doesTileExist(Tile* tile) = 0;
        virtual Resturant& addTile(Tile* tile) = 0;
        virtual Tile* getTile(int xCoord, int yCoord) = 0;
        virtual Resturant& removeTile(Tile* tile) = 0;
        virtual void placeTableInTile(Tile* tile, std::shared_ptr<Table> table) = 0;
};

#endif

