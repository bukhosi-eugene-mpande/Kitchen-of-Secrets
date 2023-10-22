#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include <vector>
#include <queue>

#include "Engine.h"

class PlayerInteraction : public GameComponent {
    private:
        Accounting* accountingSubsystem;
        Kitchen* cookingSubsystem;
        Customer* customerCareSubsystem;
        Order* orderingSubsystem;
        Reservation* reservationSubsystem;

    public:
        PlayerInteraction();
        ~PlayerInteraction();
        void payment();
        void updateInventory();
        void takeOrder();
        void orderUp();
        void seatCustomer();
};

#endif