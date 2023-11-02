#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include <vector>
#include <queue>
<<<<<<< HEAD
#include <memory>

#include "AccountingSystem.h"
#include "CustomerCareSystem.h"
#include "GameComponent.h"
#include "KitchenSystem.h"
#include "OrderSystem.h"
#include "ReservationSystem.h"

class PlayerInteraction : public GameComponent {
    private:
        AccountingSystem* accountingSystem;
        KitchenSystem* cookingSystem;
        CustomerCareSystem* customerCareSystem;
        OrderSystem* orderingSystem;
        ReservationSystem* reservationSystem;

    public:
        PlayerInteraction(Engine* engine, AccountingSystem* accountingSystem, KitchenSystem* cookingSystem, CustomerCareSystem* customerCareSystem, OrderSystem* orderingSystem, ReservationSystem* reservationSystem);
        ~PlayerInteraction();
        void payment(Customer* customer);
        void updateInventory();
        void takeOrder();
        void orderUp();
        void seatCustomers(std::vector<Customer*>);
=======

#include "Command.h"
#include "Engine.h"

class PlayerInteraction {
    private:
        std::vector<Command*> commands;
        std::vector<Command*> ordersQueue;
    public:
        PlayerInteraction(Engine* engine);
        void addCommandToVector(Command* command);
        void removeCommandFromVector(int index);
        void tabButtonPushed();
        void inventoryButtonPushed();
        void billingSystemButtonPushed();
        void waiterRoundsButtonPushed();
        void reservationsButtonPushed();
        void customerHappinessButtonPushed();
        void waiterTakesOrderButtonPushed();
        void waiterGivesOrderToCookButtonPused();
        void buildDishButtonPushed();
>>>>>>> accounting
};

#endif