#include "HalloweenOrderBuidler.h"
#include "Menu.h"
#include <set>
HalloweenOrderBuilder::HalloweenOrderBuilder(){
    std::cout<<"this is called"<<std::endl;
}

HalloweenOrderBuilder::~HalloweenOrderBuilder() {}

/// @brief this was the addDrink which adds to the order that Ive been failing to debug @Eugene
//so I will have to crape everything off
void HalloweenOrderBuilder::addDrink()
{
    Menu* drinksMenu=drinksMenuFactory.createMenu();

    std::set<std::string> itemsToAdd = {"Spider Blood", "Ghost Blood"};
    std::cout<<"Drinks Added to Menu"<<std::endl;
   // delete drinksMenu;
    //debug
     std::cout << "Items in drinksMenu:" << std::endl;
    for (const auto& item : drinksMenu->getItems()) {
        std::cout << item.first << ": " << item.second << std::endl;
    }

    for (const auto& item : drinksMenu->getItems()) {
        if (itemsToAdd.find(item.first) != itemsToAdd.end()) {
            // Debug: Print the item being added to the order.
            std::cout << "Adding to the order: " << item.first << ": " << item.second << std::endl;

            // Add the item to the order.
            this->order->items[item.first] = item.second;
        }
    }

        std::cout << "Items in the order after adding drinks:" << std::endl;
    for (const auto& item : this->order->items) {
        std::cout << item.first << ": " << item.second << std::endl;
    }


}

void HalloweenOrderBuilder::addFood()
{
    Menu* foodMenu=foodMenuFactory.createMenu();
    std::set<std::string> itemsToAdd = {"Spider Blood", "Ghost Blood"};

    std::cout<<"Drinks Food to Menu"<<std::endl;

     std::cout << "Items in Food:" << std::endl;
    for (const auto& item : foodMenu->getItems()) {
        std::cout << item.first << ": " << item.second << std::endl;
    }

   // this->order->items.insert(foodMenu->getItems().begin(), foodMenu->getItems().end());
    //delete foodMenu;
}