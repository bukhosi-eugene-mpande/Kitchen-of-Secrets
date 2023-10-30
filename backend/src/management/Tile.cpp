#include "Tile.h"

Tile::Tile(int xCoord, int yCoord) {
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

Tile::~Tile() {}

int Tile::getXCoord() {
    return xCoord;
}

void Tile::setXCoord(int xCoord) {
    this->xCoord = xCoord;
}

int Tile::getYCoord() {
    return yCoord;
}

void Tile::setYCoord(int yCoord) {
    this->yCoord = yCoord;
}

Tile* Tile::getUp() {
    return up;
}

void Tile::setUp(Tile* up) {
    this->up = up;
}

Tile* Tile::getDown() {
    return down;
}

void Tile::setDown(Tile* down) {
    this->down = down;
}

Tile* Tile::getLeft() {
    return left;
}

void Tile::setLeft(Tile* left) {
    this->left = left;
}

Tile* Tile::getRight() {
    return right;
}

void Tile::setRight(Tile* right) {
    this->right = right;
}

Table* Tile::getTable() {
    return table;
}

void Tile::setTable(Table* table) {
    this->table = table;
}

