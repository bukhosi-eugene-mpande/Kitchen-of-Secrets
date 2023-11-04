#include "Management.h"

#include "../ordering/Waiter.h"
#include "../cooking/Kitchen.h"
#include "../sudo_accounting/Inventory.h"
#include "../reservation/ReservationSystem.h"
#include "../reservation/Table.h"
#include "../reservation/Receptionist.h"
#include "../reservation/Section.h"
#include "../reservation/PrivateSection.h"
#include "../reservation/GeneralSection.h"
#include "../reservation/Reservation.h"
#include "../ordering/Order.h"
#include "../ordering/Waiter.h"
#include "../customercare/CustomerTemplate.h"
#include "../cooking/Drink.h"
#include "../cooking/Cuisine.h"

Management::Management() {
    this->inventory = std::make_shared<Inventory>(std::unordered_map<std::string,int>({{"eye of newt", 1000},{"pasta", 1000},{"ground beef", 1000},{"blood garlic", 1000},{"ectoplasmic meat", 1000},{"monster patty", 1000},{"moonlit meatballs", 1000},{"witch's fingers", 1000},{"bandage crust", 1000},{"shrieking greens", 1000},{"goblin bits", 1000},{"spooky sausages", 1000},{"pumpkin rice", 1000},{"cauldron chicken", 1000},{"skeleton ribs", 1000},{"witch's potion", 1000},{"vampire blood vodka", 1000},{"zombie virus rum", 1000},{"mummy wrap rum", 1000},{"poison apple cider", 1000},{"ectoplasmic spirit", 1000},{"moonlit whiskey", 1000},{"pumpkin rum", 1000},{"goblin ale", 1000},{"haunting wine", 1000}}));
    this->reservationSystem = std::make_shared<ReservationSystem>();
    this->receptionist = std::make_shared<Receptionist>(this->reservationSystem);
}

Management::~Management() {
}

void Management::sendOrderToKitchen(std::shared_ptr<Order> order) {
    this->kitchen->addOrder(order);
}

std::shared_ptr<Order> Management::getOrderFromKitchen(Waiter* waiter) {
    return this->kitchen->getPreparedOrder(waiter);
}

std::shared_ptr<Order> Management::getCanceledOrderFromKitchen(Waiter* waiter) {
    return this->kitchen->getCanceledOrder(waiter);
}

bool Management::requestIngredients(std::unordered_map<std::string,int> ingredients) {
    return this->inventory->requestIngredients(ingredients);
}

void Management::notifyWaiterOfCancellation(Waiter* waiter) {
    waiter->getCanceledOrderFromKitchen();
}

void Management::notifyWaiterOfCompletion(Waiter* waiter) {
    waiter->getOrderFromKitchen();
}

void Management::setKitchen(std::shared_ptr<Kitchen> kitchen) {
    this->kitchen = kitchen;
}

void Management::setInventory(std::shared_ptr<Inventory> inventory){
    this->inventory = inventory;
}

void Management::notifyPlayerOfChangeInMood() {
    // TODO - implement a function in the ui that will display a message to the player
}

void Management::clearOutTable(std::shared_ptr<Table> table) {
    this->reservationSystem->clearOutTable(table);
}

void Management::requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section) {
    this->receptionist->requestReservation(customer,section);
}

void Management::requestToBeSeated(std::shared_ptr<CustomerTemplate> customer) {
    this->receptionist->requestToBeSeated(customer);
}

std::shared_ptr<Section> Management::getGeneralSection() {
    return this->reservationSystem->getGeneralSection();
}

std::shared_ptr<Section> Management::getPrivateSection() {
    return this->reservationSystem->getPrivateSection();
}

std::vector<std::shared_ptr<CustomerTemplate>> Management::getCustomers() {
    return this->reservationSystem->getCustomers();
}

std::shared_ptr<Drink> Management::getDrink(std::string name) {
    return this->kitchen->getDrink(name);
}

std::shared_ptr<Cuisine> Management::getCusine(std::string name) {
    return this->kitchen->getCusine(name);
}

std::unordered_map<int,std::string> Management::getDrinksMenu(){
    return this->kitchen->getDrinksMenu();
}

std::unordered_map<int,std::string> Management::getCuisineMenu(){
    return this->kitchen->getCuisineMenu();
}
