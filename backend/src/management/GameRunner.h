#ifndef Game_Runner_H
#define Game_Runner_H

#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

#include "../customercare/CustomerTemplate.h"
#include "../customercare/Customer.h"
#include "../customercare/CustomerNPC.h"
#include "../ordering/Waiter.h"
#include "../cooking/Kitchen.h"
#include "../cooking/HeadChef.h"
#include "PlayerInteraction.h"

class GameRunner{

    private:
        std::shared_ptr<PlayerInteraction> playerInteraction;

        std::shared_ptr<Kitchen> kitchen;

        std::shared_ptr<Customer> customer;

        std::shared_ptr<CustomerNPC> customer2;

        std::shared_ptr<Waiter> waiter;

        bool foodFlag;

        bool beverageFlag;

    public:
        GameRunner();

        void startGame(std::string section);

        void requestReservation(std::string section);

        void sendBeverageOrder(std::unordered_map<std::string,int> order);

        void sendFoodOrder(std::unordered_map<std::string,int> order);

        void changeMood();

        std::string payment(std::string payment,double bill);

        void doRoundsChef();

        void doRoundsWaiter();

        std::unordered_map<int,std::string> getFoodMenu();

        std::unordered_map<int,std::string> getBeverageMenu();

};


#endif