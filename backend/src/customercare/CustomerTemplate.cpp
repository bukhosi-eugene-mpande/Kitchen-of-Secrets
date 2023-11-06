#include "CustomerTemplate.h"
#include "SatisfactionState.h"
#include "Happy.h"

//reservation
#include "../reservation/Reservation.h"

//system interaction
#include "../management/PlayerInteraction.h"

//ordering
#include "../ordering/Waiter.h"
#include "../ordering/Menu.h"

CustomerTemplate::CustomerTemplate(std::string name,std::shared_ptr<PlayerInteraction> management){
    this->name = name;
    this->management = management;
    this->Mood = std::make_shared<Happy>(this);
    this->readyToOrder = false;
    this->readyToPay = false;
    this->isEating=false;
    this->ordered = false;
    this->totalBill = 0;
    this->reservation = nullptr;
    this->isDoneEating = false;
    this->paymentType = "card";
}

CustomerTemplate::~CustomerTemplate(){
    
}

std::shared_ptr<SatisfactionState> CustomerTemplate::getMood(){
    return this->Mood;
}

void CustomerTemplate::setIsEating()
{
    this->isEating=true;
}

bool CustomerTemplate::getIsEating()
{
    return this->isEating;
}
double CustomerTemplate::calculateFinalBill(double bill){
    return this->Mood->calculateBill(bill);
}

void CustomerTemplate::setMood(std::shared_ptr<SatisfactionState> Mood){
    this->Mood = Mood;
}

std::unordered_map<std::string,int> CustomerTemplate::getOrder(){
    return this->order;
}

void CustomerTemplate::setOrder(std::unordered_map<std::string,int> order){
    this->order = order;
}

double CustomerTemplate::getTotalBill(){
    return this->totalBill;
}

void CustomerTemplate::setReadyToOrder(bool readyToOrder)
{
    this->readyToOrder = readyToOrder;
}

void CustomerTemplate::setReadyToPay(bool readyToPay)
{
    this->readyToPay = readyToPay;
}

void CustomerTemplate::console(){
    this->Mood->console();
}

void CustomerTemplate::anger(){
    this->Mood->anger();
}

void CustomerTemplate::notifyPlayerInteraction(){
    this->management->notifyPlayerOfChangeInMood();
}

void CustomerTemplate::leave(){
    this->guests.clear();
    this->management->clearOutTable(reservation->getTable());
}

std::string CustomerTemplate::getName(){
    return this->name;
}

std::string CustomerTemplate::getPaymentType()
{
    return this->paymentType;
}

std::string CustomerTemplate::setpaymentType(std::string paymentType){
    this->paymentType = paymentType;
    return this->paymentType;
}

bool CustomerTemplate::IsReadyToOrder(){
    return this->readyToOrder;
}

bool CustomerTemplate::IsReadyToPay()
{
    return this->readyToPay;
}

std::shared_ptr<Reservation> CustomerTemplate::getReservation(){
    return this->reservation;
}

void CustomerTemplate::setReservation(std::shared_ptr<Reservation> reservation){
    this->reservation = reservation;
}

std::shared_ptr<PlayerInteraction> CustomerTemplate::getPlayerInteraction(){
    return this->management;
}

void CustomerTemplate::setPlayerInteraction(std::shared_ptr<PlayerInteraction> management){
    this->management = management;
}

std::shared_ptr<CustomerTemplate> CustomerTemplate::this_to_shared(){
    return std::shared_ptr<CustomerTemplate>(this);
}

void CustomerTemplate::requestReservation(){
    this->management->requestReservation(this->this_to_shared(),this->DesiredSection);
}

void CustomerTemplate::addGuest(std::shared_ptr<CustomerTemplate> guest){
    this->guests.push_back(guest);
}

std::vector<std::shared_ptr<CustomerTemplate>> CustomerTemplate::getGuests(){
    return this->guests;
}

bool CustomerTemplate::getHasGuests(){
    return this->hasGuests;
}

void CustomerTemplate::setHasGuests(bool hasGuests){
    this->hasGuests = hasGuests;
}

bool CustomerTemplate::getIsMain(){
    return this->isMain;
}

void CustomerTemplate::setIsMain(bool isMain){
    this->isMain = isMain;
}

int CustomerTemplate::getNumGuests(){
    return this->numberOfGuests;
}

void CustomerTemplate::setNumGuests(int numGuests){
    this->numberOfGuests = numGuests;
}

std::string CustomerTemplate::getDesiredSection(){
    return this->DesiredSection;
}

void CustomerTemplate::setDesiredSection(std::string DesiredSection){
    this->DesiredSection = DesiredSection;
}

void CustomerTemplate::requestToBeSeated(){
    this->management->requestToBeSeated(this->this_to_shared());
}

int CustomerTemplate::generateRandomNum(int min, int max){
    srand(time(0)); 
    return min + rand() % (max - min + 1); 
}

std::unordered_map<std::string,int> CustomerTemplate::getBeverageOrder(){
    return this->BevarageOrder;
}

std::unordered_map<std::string,int> CustomerTemplate::getFoodOrder(){
    return this->FoodOrder;
}

void CustomerTemplate::setBeverageOrder(std::unordered_map<std::string,int> order){
    this->BevarageOrder = order;
}

void CustomerTemplate::setFoodOrder(std::unordered_map<std::string,int> order){
    this->FoodOrder = order;
}

std::unordered_map<std::string, int> CustomerTemplate::generateBeverageOrder(std::shared_ptr<Menu> menu){
    std::unordered_map<std::string, int> order;
    int numBeverages = generateRandomNum(1,3);
    for(int i = 0; i < numBeverages; i++){
        int beverageIndex = generateRandomNum(1, 10);
        std::string beverage = menu->getMenuItems()[beverageIndex];
        int quantity = generateRandomNum(1,3);
        order[beverage] = quantity;
    }
    return order;
}

std::unordered_map<std::string, int> CustomerTemplate::generateFoodOrder(std::shared_ptr<Menu> menu){
    std::unordered_map<std::string, int> order;
    int num = generateRandomNum(1,3);
    for(int i = 0; i < num; i++){
        int foodIndex = generateRandomNum(1, 15);
        std::string beverage = menu->getMenuItems()[foodIndex];
        int quantity = generateRandomNum(1,3);
        order[beverage] = quantity;
    }
    return order;
}

std::unordered_map<std::string,int> CustomerTemplate::requestBeverageOrder(std::shared_ptr<Menu> menu){
    if(this->name == "NPC"){
        return generateBeverageOrder(menu);
    }else{
        return getBeverageOrder();
    }
}

std::unordered_map<std::string,int> CustomerTemplate::requestFoodOrder(std::shared_ptr<Menu> menu){
    if(this->name == "NPC"){
        return generateFoodOrder(menu);
    }else{
        return getFoodOrder();
    }
}

void CustomerTemplate::setOrdered(bool ordered){
    this->ordered = ordered;
}

bool CustomerTemplate::getOrdered(){
    return this->ordered;
}

void CustomerTemplate::setFinishedOrder(std::shared_ptr<Order> order){
    this->finishedOrder = order;
}

std::shared_ptr<Order> CustomerTemplate::getFinishedOrder(){
    return this->finishedOrder;
}

void CustomerTemplate::setTotalBill(double bill){
    this->totalBill = bill;
}


void CustomerTemplate::setPaymentType(std::string paymentType){
    this->paymentType = paymentType;
}

bool CustomerTemplate::getDoneEating(){
    return this->isDoneEating;
}

void CustomerTemplate::setDoneEating(bool isDoneEating){
    this->isDoneEating = isDoneEating;
}

void CustomerTemplate::setManagement(std::shared_ptr<PlayerInteraction> management){
    this->management = management;
}