#include "ResturantPlayground.h"

ResturantPlayground::ResturantPlayground() : Resturant() {}

ResturantPlayground::~ResturantPlayground() {}

ResturantIterator *ResturantPlayground::createIterator(Tile* startingTile)
{
    return nullptr;
}

Resturant &ResturantPlayground::addEdge(Tile* source, Tile* destination)
{
    if (source != nullptr) {
        if (source != destination || (source->getXCoord() != destination->getXCoord() && source->getYCoord() != destination->getYCoord())) {
            std::set<Tile*> destinations = map[source];
            if (destinations.empty()) {
                destinations = std::set<Tile*>();
            }
            if (destination != NULL) {
                destinations.insert(destination);
                std::set<Tile*> destinationsOfDestination = map[destination];
                if (destinationsOfDestination.empty()) {
                    map[destination] = std::set<Tile*>();
                }
            }
            map[source] = destinations;
        }
    }
    return *this;
}

std::set<Tile*> ResturantPlayground::getNeighbours(Tile* tile)
{
    std::set<Tile*> neighbours = this->map[tile];
    if (neighbours.empty()) {
        return std::set<Tile*>();
    } else {
        return neighbours;
    }
}

bool ResturantPlayground::doesTileExist(Tile* tile)
{
    return map.count(tile) > 0;
}

Resturant &ResturantPlayground::addTile(Tile* tile)
{
    if (tile != nullptr && !doesTileExist(tile)) {
        map[tile] = std::set<Tile*>();
    }
    return *this;
}

Tile *ResturantPlayground::getTile(int xCoord, int yCoord)
{
    for (auto& entry : map)
    {
        Tile* tile = entry.first;
        if (tile->getXCoord() == xCoord && tile->getYCoord() == yCoord)
        {
            return tile;
        }
    }
    return nullptr;
}

Resturant &ResturantPlayground::removeTile(Tile* tile)
{
    if (tile != nullptr) {
        map.erase(tile);

        for (auto& entry : map) {
            entry.second.erase(tile);
        }
    }
    return *this;
}

void ResturantPlayground::placeTableInTile(Tile* tile, Table* table)
{
    if (doesTileExist(tile)) {
        table->placeTable(tile->getXCoord(), tile->getYCoord());
    }
}
