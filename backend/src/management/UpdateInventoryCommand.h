#ifndef UPDATE_INVENTORY_COMMAND_H
#define UPDATE_INVENTORY_COMMAND_H

#include "Command.h"
#include "Bank.h"

/**
 * @brief 
 * 
 */
class UpdateInventoryCommand : public Command {
    private:
        /**
         * @brief 
         * 
         */
        Inventory* inventory;

        /**
         * @brief 
         * 
         */
        Bank* bank;
    public:
        /**
         * @brief Construct a new Update Inventory Command object
         * 
         * @param inventory 
         * @param bank 
         */
        UpdateInventoryCommand(Inventory* inventory, Bank* bank);

        /**
         * @brief Destroy the Update Inventory Command object
         * 
         */
        ~UpdateInventoryCommand();

        /**
         * @brief 
         * 
         */
        virtual void execute();
};

#endif