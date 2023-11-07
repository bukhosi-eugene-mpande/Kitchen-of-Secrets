#ifndef DeputyHeadChef_H
#define DeputyHeadChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"
#include "Chef.h"

class Management;


/**
 * @class DeputyHeadChef
 * @brief A class representing a deputy head chef in a kitchen.
 * 
 * This class inherits from the StationChef class and adds additional functionality
 * specific to the deputy head chef role, such as the ability to manage player interactions.
 */
class DeputyHeadChef : public StationChef {
    private: 
        PlayerInteraction* management; /**< A pointer to the player interaction object. */
        bool flag; /**< A boolean flag used for internal logic. */
        
    public:

        /**
         * @brief Constructor for the DeputyHeadChef class.
         * @param kitchen A pointer to the kitchen object.
         */
        DeputyHeadChef(Kitchen* kitchen);

        /**
         * @brief Destructor for the DeputyHeadChef class.
         */
        ~DeputyHeadChef();

        /**
         * @brief Prepares an order.
         * @param order A shared pointer to the order object.
         */
        void prepareOrder(std::shared_ptr<Order> order);

        /**
         * @brief Sets the next chef in the chain of command.
         */
        void setNextChef();

        /**
         * @brief Cancels an order.
         * @param order A shared pointer to the order object.
         */
        void cancelOrder(std::shared_ptr<Order> order);

        /**
         * @brief Finishes an order.
         * @param order A shared pointer to the order object.
         */
        void finishOrder(std::shared_ptr<Order> order);
        
        /**
         * @brief Gets the kitchen object.
         * @return A pointer to the kitchen object.
         */
        Kitchen* getKitchen() const;

        /**
         * @brief Sets the management object.
         */
        void setManagement();

};

#endif