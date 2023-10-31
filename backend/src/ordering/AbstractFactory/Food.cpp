#include "Food.h"

Food::Food():Menu("")
{
    std::cout<<"-----------------New Food Menu created.--------------"<<std::endl;
    std::cout<<std::endl;
}
void Food::setItems(std::map<std::string, double> items)
{
    this->items={{"Spider Pizza", 10.99}, {"Ghost Burger", 11.99}, {"Venom Salad", 12.99},{"Bloody Bread", 13.99},{"Pumpkin Pizza", 14.99}, {"Witch's Spaghetti", 15.99},{"Zombie Prawn", 16.99},{"Poisedon Platter", 17.99}, {"Invisible Rolls",18.99}, {"Scary Salami", 19.99}};
}

void Food::displayMenu()
{
    std::cout << "Food Menu:\n";
        for (const auto& item : getItems())
        {
            std::cout << "- " << item.first << ": $" << item.second << '\n';
        }
}