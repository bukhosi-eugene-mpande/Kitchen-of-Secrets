#ifndef PLAYER_INTERACTION_H
#define PLAYER_INTERACTION_H

#include <vector>
#include <queue>

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
};

#endif