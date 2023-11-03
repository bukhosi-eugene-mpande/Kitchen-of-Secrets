#ifndef CONCRETEMENUITEM_H
#define CONCRETEMENUITEM_H
#include "MenuItem.h"
#include <memory>
class ConcreteMenuItem : public MenuItem {
public:
    ConcreteMenuItem(double price, const std::string& name, const std::unordered_map<std::string, int>& ingredients)
        : MenuItem(price, name, ingredients) {}

    std::shared_ptr<MenuItem> clone() override {
        return std::make_shared<ConcreteMenuItem>(*this);
    }
};
#endif