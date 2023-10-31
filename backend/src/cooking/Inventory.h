#ifndef Inventory_H
#define Inventory_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

class Inventory {
    private:
    std::unordered_map<std::string,int> inventory;

    public:

        Inventory(std::unordered_map<std::string,int> inventory);

        Inventory(const Inventory& other);

        ~Inventory();

        bool requestIngredients(std::unordered_map<std::string,int> ingredients);

        std::unordered_map<std::string,int> getInventory() const;


};

#endif