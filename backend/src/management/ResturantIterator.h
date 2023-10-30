#ifndef RESTURANT_ITERATOR_H
#define RESTURANT_ITERATOR_H

#include "Tile.h"

class Resturant;

class ResturantIterator
{
public:
    ResturantIterator();
    virtual ~ResturantIterator();
    virtual Tile* next() = 0;
    virtual bool hasNext() const = 0;
};

#endif

