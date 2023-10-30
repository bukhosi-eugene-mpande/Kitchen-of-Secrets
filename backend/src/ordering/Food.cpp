#include "Food.h"

Food::Food():Menu("", std::vector<std::string>())
{
    std::cout<<"New Food Menu created."<<std::endl;

}
std::vector<std::string> Food::getItems()
{
    return {"Spider Pizza", "Ghost Burger", "Venom Salad", "Bloody Bread", "Pumpkin Pizza", "Witch's Spaghetti", "Zombie Prawn", "Poisedon Platter", "Invisible Rolls", "Scary Salami"};
}

void Food::displayMenu()
{
    std::cout << "Food Menu:\n";
        for (const auto& item : getItems())
        {
            std::cout << "- " << item << '\n';
        }
}