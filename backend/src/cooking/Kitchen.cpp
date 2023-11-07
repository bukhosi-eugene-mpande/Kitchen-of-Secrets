#include <iostream>
#include "Kitchen.h"
#include "DeputyHeadChef.h"
#include "Meal.h"
#include "HeadChef.h"
#include "Cuisine.h"
#include "Drink.h"
#include "../management/PlayerInteraction.h"
#include "../ordering/Order.h"
#include "../ordering/Waiter.h"

Kitchen::Kitchen(PlayerInteraction* management) {
    this->management = management;

    this->deputyHeadChef = std::make_shared<DeputyHeadChef>(this);

    this->headChef = std::make_shared<HeadChef>(this, management);
    
    this->generateCusines();

    this->generateDrinks();

    for(auto meal : this->cuisines){
        this->AvailableMeals[meal.second.get()->getName()] = meal.second;
    }

    for(auto meal : this->drinks){
        this->AvailableMeals[meal.second.get()->getName()] = meal.second;
    }
}

Kitchen::~Kitchen(){
    
}


void Kitchen::addMeal(std::shared_ptr<Meal> meal)
{
    this->AvailableMeals[meal->getName()] = meal;
}

void Kitchen::addOrder(std::shared_ptr<Order> order)
{
    if(this->deputyHeadChef != nullptr){
        this->deputyHeadChef->prepareOrder(order);
    }else{
        this->createDeputyHeadChef();
        this->deputyHeadChef->prepareOrder(order);
    }
}

void Kitchen::removeMeal(std::string name)
{
    this->AvailableMeals.erase(name);
}

std::string Kitchen::getChefName(std::string Meal)
{
    return this->AvailableMeals[Meal]->getChef();
}

std::shared_ptr<Order> Kitchen::getPreparedOrder(Waiter* waiter)
{
    for (auto it = this->preparedOrders.begin(); it != this->preparedOrders.end(); ++it) {
        if ((*it)->getWaiter() == waiter) {
            this->preparedOrders.erase(it);
            return *it;
        }
    }
    return nullptr;
}

std::shared_ptr<Order> Kitchen::getCanceledOrder(Waiter* waiter)
{
    for (auto it = this->canceledOrders.begin(); it != this->canceledOrders.end(); ++it) {
        if ((*it)->getWaiter() == waiter) {
            this->canceledOrders.erase(it);
            return *it;
        }
    }
    return nullptr;
}

std::unordered_map<std::string,int> Kitchen::getIngredients(std::string name)
{
    return this->AvailableMeals[name]->getIngredients();
}

double Kitchen::getPrice(std::string name)
{
    return this->AvailableMeals[name]->getPrice();
}

std::unordered_map<int,std::string> Kitchen::getMenu()
{
    std::unordered_map<int,std::string> menu;
    int i = 1;
    for (auto meal : this->AvailableMeals) {
        menu[i] = meal.first;
        i++;
    }
    return menu;
}

std::unordered_map<int,std::string> Kitchen::getDrinksMenu()
{
    std::unordered_map<int,std::string> menu;
    int i = 1;
    for (auto drink : this->drinks) {
        menu[i] = drink.first;
        i++;
    }
    return menu;
}

std::unordered_map<int,std::string> Kitchen::getCuisineMenu()
{
    std::unordered_map<int,std::string> menu;
    int i = 1;
    for (auto cuisine : this->cuisines) {
        menu[i] = cuisine.first;
        i++;
    }
    return menu;
}

PlayerInteraction* Kitchen::getManagement() const
{
    return this->management;
}

void Kitchen::cancelOrder(std::shared_ptr<Order> order)
{
    this->canceledOrders.push_back(order);
    this->management->notifyWaiterOfCancellation(order->getWaiter());
}

void Kitchen::finishOrder(std::shared_ptr<Order> order)
{
    this->preparedOrders.push_back(order);
    this->management->notifyWaiterOfCompletion(order->getWaiter());
}

void Kitchen::createHeadChef(){
    if(this->headChef == nullptr){
        this->headChef = std::make_shared<HeadChef>(this, this->management);
    }
}

void Kitchen::createDeputyHeadChef(){
    if(this->deputyHeadChef == nullptr){
        this->deputyHeadChef = std::make_shared<DeputyHeadChef>(this);
    }
}

std::unordered_map<std::string,std::shared_ptr<Meal>> Kitchen::getAvailableMeals() const{
    return this->AvailableMeals;
}

std::shared_ptr<HeadChef> Kitchen::getHeadChef() const{
    return this->headChef;
}

std::shared_ptr<DeputyHeadChef> Kitchen::getDeputyHeadChef() const{
    return this->deputyHeadChef;
}

std::vector<std::shared_ptr<Order>> Kitchen::getPreparedOrders() const{
    return this->preparedOrders;
}

std::vector<std::shared_ptr<Order>> Kitchen::getCanceledOrders() const{
    return this->canceledOrders;
}

std::vector<std::string> Kitchen::generateListOfResposibilties(std::string chefName){
    std::vector<std::string> responsibilities;

    for(auto meal : this->AvailableMeals){
        if(meal.second.get()->getChef() == chefName){
            responsibilities.push_back(meal.second.get()->getName());
        }
    }

    return responsibilities;
}

std::shared_ptr<Drink> Kitchen::getDrink(std::string name){
    return this->drinks[name];
}

std::shared_ptr<Cuisine> Kitchen::getCusine(std::string name){
    return this->cuisines[name];
}

void Kitchen::generateCusines(){
    //these are the cuseines that are available in the restaurant
    std::unordered_map<std::string, int> ingre1 = {{"eye of newt", 2}};
    std::shared_ptr<Cuisine> cus1 = std::make_shared<Cuisine>(13.99, "Witch's Brew Stew", "Deputy Head Chef", ingre1);
    cuisines["Witch's Brew Stew"] = cus1;

    std::unordered_map<std::string, int> ingre2 = {{"pasta", 2}};
    std::shared_ptr<Cuisine> cus2 = std::make_shared<Cuisine>(11.99, "Zombie Brain Pasta", "Deputy Head Chef", ingre2);
    cuisines["Zombie Brain Pasta"] = cus2;

    std::unordered_map<std::string, int> ingre3 = {{"ground beef", 2}};
    std::shared_ptr<Cuisine> cus3 = std::make_shared<Cuisine>(12.99, "Mummy Meatloaf", "Deputy Head Chef", ingre3 );
    cuisines["Mummy Meatloaf"] = cus3;

    std::unordered_map<std::string, int> ingre4 = {{"blood garlic", 2}};
    std::shared_ptr<Cuisine> cus4 = std::make_shared<Cuisine>(14.99, "Vampire Garlic Bread", "Baker", ingre4);
    cuisines["Vampire Garlic Bread"] = cus4;

    std::unordered_map<std::string, int> ingre5 = {{"ectoplasmic meat", 2}};
    std::shared_ptr<Cuisine> cus5 = std::make_shared<Cuisine>(10.99, "Ghostly Goulash", "Baker", ingre5);
    cuisines["Ghostly Goulash"] = cus5;

    std::unordered_map<std::string, int> ingre6 = {{"monster patty", 2}};
    std::shared_ptr<Cuisine> cus6 = std::make_shared<Cuisine>(13.99, "Frankenstein's Monster Burger", "Baker", ingre6);
    cuisines["Frankenstein's Monster Burger"] = cus6;

    std::unordered_map<std::string, int> ingre7 = {{"moonlit meatballs", 2}};
    std::shared_ptr<Cuisine> cus7 = std::make_shared<Cuisine>(11.99, "Werewolf Bites", "Cook", ingre7);
    cuisines["Werewolf Bites"] = cus7;

    std::unordered_map<std::string, int> ingre8 = {{"witch's fingers", 2}};
    std::shared_ptr<Cuisine> cus8 = std::make_shared<Cuisine>(12.99, "Wicked Witch Fingers", "Cook", ingre8);
    cuisines["Wicked Witch Fingers"] = cus8;

    std::unordered_map<std::string, int> ingre9 = {{"bandage crust", 2}};
    std::shared_ptr<Cuisine> cus9 = std::make_shared<Cuisine>(14.99, "Mummy Mummy Pizza", "Cook", ingre9);
    cuisines["Mummy Mummy Pizza"] = cus9;

    std::unordered_map<std::string, int> ingre10 = {{"shrieking greens", 2}};
    std::shared_ptr<Cuisine> cus10 = std::make_shared<Cuisine>(10.99, "Screaming Salad", "Fry Chef", ingre10);
    cuisines["Screaming Salad"] = cus10;

    std::unordered_map<std::string, int> ingre11 = {{"goblin bits", 2}};
    std::shared_ptr<Cuisine> cus11 = std::make_shared<Cuisine>(13.99, "Goblin Gumbo", "Fry Chef", ingre11);
    cuisines["Goblin Gumbo"] = cus11;

    std::unordered_map<std::string, int> ingre12 = {{"spooky sausages", 2}};
    std::shared_ptr<Cuisine> cus12 = std::make_shared<Cuisine>(11.99, "Haunted Hot Dogs", "Fry Chef", ingre12);
    cuisines["Haunted Hot Dogs"] = cus12;

    std::unordered_map<std::string, int> ingre13 = {{"pumpkin rice", 2}};
    std::shared_ptr<Cuisine> cus13 = std::make_shared<Cuisine>(12.99, "Pumpkin Patch Risotto", "Grill Chef", ingre13);
    cuisines["Pumpkin Patch Risotto"] = cus13;

    std::unordered_map<std::string, int> ingre14 = {{"cauldron chicken", 2}};
    std::shared_ptr<Cuisine> cus14 = std::make_shared<Cuisine>(14.99, "Cursed Cauldron Curry", "Grill Chef", ingre14);
    cuisines["Cursed Cauldron Curry"] = cus14;

    std::unordered_map<std::string, int> ingre15 = {{"skeleton ribs", 2}};
    std::shared_ptr<Cuisine> cus15 = std::make_shared<Cuisine>(10.99, "Skeletal Ribs", "Grill Chef", ingre15);
    cuisines["Skeletal Ribs"] = cus15;

}

void Kitchen::generateDrinks(){
    //these are the drinks that are available in the restaurant
    std::unordered_map<std::string, int> ingre1 = {{"witch's potion", 2}};
    std::shared_ptr<Drink> drink1 = std::make_shared<Drink>(false, 9.99, "Witches' Brew Punch", "Deputy Head Chef", ingre1);
    drinks["Witches' Brew Punch"] = drink1;

    std::unordered_map<std::string, int> ingre2 = {{"vampire blood vodka", 2}};
    std::shared_ptr<Drink> drink2 = std::make_shared<Drink>(true, 8.99, "Vampire's Kiss Martini", "Deputy Head Chef", ingre2);
    drinks["Vampire's Kiss Martini"] = drink2;

    std::unordered_map<std::string, int> ingre3 = {{"zombie virus rum", 2}};
    std::shared_ptr<Drink> drink3 = std::make_shared<Drink>(false, 7.99, "Zombie Elixir", "Deputy Head Chef", ingre3);
    drinks["Zombie Elixir"] = drink3;

    std::unordered_map<std::string, int> ingre4 = {{"mummy wrap rum", 2}};
    std::shared_ptr<Drink> drink4 = std::make_shared<Drink>(true, 10.99, "Mummy Mojito", "Deputy Head Chef", ingre4);
    drinks["Mummy Mojito"] = drink4;

    std::unordered_map<std::string, int> ingre5 = {{"poison apple cider", 2}};
    std::shared_ptr<Drink> drink5 = std::make_shared<Drink>(false, 8.99, "Wicked Witch's Cider", "Deputy Head Chef", ingre5);
    drinks["Wicked Witch's Cider"] = drink5;

    std::unordered_map<std::string, int> ingre6 = {{"ectoplasmic spirit", 2}};
    std::shared_ptr<Drink> drink6 = std::make_shared<Drink>(false, 9.99, "Ghostly Goblet", "Deputy Head Chef", ingre6);
    drinks["Ghostly Goblet"] = drink6;

    std::unordered_map<std::string, int> ingre7 = {{"moonlit whiskey", 2}};
    std::shared_ptr<Drink> drink7 = std::make_shared<Drink>(true, 10.99, "Werewolf Whiskey Sour", "Deputy Head Chef", ingre7);
    drinks["Werewolf Whiskey Sour"] = drink7;

    std::unordered_map<std::string, int> ingre8 = {{"pumpkin rum", 2}};
    std::shared_ptr<Drink> drink8 = std::make_shared<Drink>(false, 7.99, "Pumpkin Spice Potion", "Deputy Head Chef", ingre8);
    drinks["Pumpkin Spice Potion"] = drink8;

    std::unordered_map<std::string, int> ingre9 = {{"goblin ale", 2}};
    std::shared_ptr<Drink> drink9 = std::make_shared<Drink>(false, 9.99, "Goblin Grog", "Deputy Head Chef", ingre9);
    drinks["Goblin Grog"] = drink9;

    std::unordered_map<std::string, int> ingre10 = {{"haunting wine", 2}};
    std::shared_ptr<Drink> drink10 = std::make_shared<Drink>(true, 8.99, "Spectral Sangria", "Deputy Head Chef", ingre10);
    drinks["Spectral Sangria"] = drink10;
}