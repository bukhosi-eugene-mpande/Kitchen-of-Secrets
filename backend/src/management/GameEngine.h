#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Engine.h"

// accounting
#include "backend/src/accounting/Billing/Billing.h"
#include "backend/src/accounting/Billing/CardBill.h"
#include "backend/src/accounting/Billing/CashBill.h"
#include "backend/src/accounting/Billing/MultiBill.h"
#include "backend/src/accounting/Tab/Tab.h"
#include "backend/src/accounting/Tab/OpenTab.h"
#include "backend/src/accounting/Tab/CloseTab.h"
#include "backend/src/accounting/Tab/OverdueTab.h"
#include "backend/src/accounting/Inventory/FoodInventory.h"
#include "backend/src/accounting/Inventory/BeverageInventory.h"

//cooking
#include "backend/src/cooking/Baker.h"
#include "backend/src/cooking/Cook.h"
#include "backend/src/cooking/GrillChef.h"
#include "backend/src/cooking/FryChef.h"
#include "backend/src/cooking/HeadChef.h"
#include "backend/src/cooking/Kitchen.h"
#include "backend/src/cooking/Food.h"
#include "backend/src/cooking/Beverage.h"
#include "backend/src/cooking/Order.h"
/*
class GameEngine : public Engine {
    private:
        // accounting
        std::shared_ptr<Tab> tab;
        std::shared_ptr<Billing> billing;

        // cooking
        std::shared_ptr<Baker> baker;
        std::shared_ptr<Cook> cook;
        std::shared_ptr<GrillChef> grillChef;
        std::shared_ptr<FryChef> fryChef;
        std::shared_ptr<HeadChef> headChef;
        std::shared_ptr<Kitchen> kitchen;
        std::shared_ptr<Food> food;
        std::shared_ptr<Beverage> beverage;
        std::shared_ptr<Order> order;

        // customer
        std::shared_ptr<GameComponent> customer;
        

        // ordering
        std::shared_ptr<GameComponent> drinks;
        std::shared_ptr<GameComponent> food;
        std::shared_ptr<GameComponent> menu;

        // reservation
        std::shared_ptr<GameComponent> table;
        std::shared_ptr<GameComponent> reservationSystem;
        std::shared_ptr<GameComponent> receptionist;

    protected:
        virtual void createGameComponents();
    public:
    
        GameEngine();
        ~GameEngine();
        virtual void notify(std::shared_ptr<GameComponent> sender, std::string message);
        void reactOnGameComponent(int index);
};
*/

class GameEngine : public Engine {
    private:
        std::vector<std::shared_ptr<GameComponent>> components;
    public:
        virtual void notify(std::shared_ptr<GameComponent> sender, std::string event);
        virtual void registerComponent(std::shared_ptr<GameComponent> component) = 0;
        virtual void unregisterComponent(std::shared_ptr<GameComponent> component) = 0;
}
#endif