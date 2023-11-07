#include "GameRunner.h"

GameRunner::GameRunner(){
    this->playerInteraction = std::make_shared<PlayerInteraction>();
    this->tab = std::make_shared<Tab>();
    this->foodFlag = false;
    this->beverageFlag = false;

}

void GameRunner::startGame(std::string section){
    this->kitchen = std::make_shared<Kitchen>(this->playerInteraction.get());
    this->playerInteraction->setKitchen(this->kitchen);
    this->customer2 = std::make_shared<CustomerNPC>(this->playerInteraction,true,section);

    if(section == "Private Section"){
        this->customer = std::make_shared<Customer>(this->playerInteraction);
        waiter = std::make_shared<Waiter>(this->playerInteraction->getPrivateSection().get(), this->playerInteraction.get());
    }else{
        this->customer = std::make_shared<Customer>(this->playerInteraction);
        waiter = std::make_shared<Waiter>(this->playerInteraction->getGeneralSection().get(), this->playerInteraction.get());
    }
}

void GameRunner::requestReservation(std::string section){

    this->startGame(section);

    this->customer->setManagement(playerInteraction);
    this->customer->setDesiredSection("Private Section");
    this->customer->requestReservation();
    this->customer->requestToBeSeated();

    customer2->setManagement(playerInteraction);
    customer2->requestReservation();
    customer2->requestToBeSeated();
}

void GameRunner::sendBeverageOrder(std::unordered_map<std::string,int> order){
    customer->setBeverageOrder(order);
    beverageFlag = true;
    if(foodFlag && beverageFlag){
        waiter->doOrderRounds();
    }
}

void GameRunner::sendFoodOrder(std::unordered_map<std::string,int> order){
    customer->setFoodOrder(order);
    foodFlag = true;
    if(foodFlag && beverageFlag){
        waiter->doOrderRounds();
    }
}

void GameRunner::changeMood(){
    customer->anger();
}

std::string GameRunner::payment(std::string payment,double bill){
    return playerInteraction->pay(payment,bill);
}

void GameRunner::doRoundsChef(){
    kitchen->getHeadChef()->goOnRounds();
}

std::unordered_map<int, std::string>  GameRunner::getFoodMenu(){
    return this->playerInteraction->getCuisineMenu();
}

std::unordered_map<int, std::string>  GameRunner::getBeverageMenu(){
    return this->playerInteraction->getDrinksMenu();
}

void GameRunner::doRoundsWaiter(){
    waiter->doOrderRounds();
}

std::string GameRunner::addToTab(double cost){
    return tab->addOrderCost(cost);
}

std::shared_ptr<Tab> GameRunner::getTab(){
    return tab;
}