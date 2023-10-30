#ifndef RESTURANT_PLAYGROUND_H
#define RESTURNAT_PLAYGROUND_H

#include "Resturant.h"

class ResturantPlayground : Resturant {
    private:
        std::map<Tile*, std::set<Tile*>> map;
    public:
        ResturantPlayground();
        virtual ~ResturantPlayground();
        virtual ResturantIterator* createIterator(Tile* startingTile);
        virtual Resturant& addEdge(Tile* source, Tile* destination);
        virtual std::set<Tile*> getNeighbours(Tile* tile);
        virtual bool doesTileExist(Tile* tile);
        virtual Resturant& addTile(Tile* tile);
        virtual Tile* getTile(int xCoord, int yCoord);
        virtual Resturant& removeTile(Tile* tile);
        virtual void placeTableInTile(Tile* tile, Table* table);
};

#endif

