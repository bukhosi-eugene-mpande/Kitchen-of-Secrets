#ifndef ORDER_H
#define ORDER_H
#include "iostream"
#include <map>
#include <string>
//this is the product of the OrderBuilder

class Order
{
    public:
        std::map<std::string, double> items;
        void listItems() const;
};
#endif