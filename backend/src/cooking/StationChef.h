#ifndef STATION_CHEF_H
#define STATION_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

/**
 * @brief The StationChef class represents a chef who is responsible for preparing a specific type of dish in the kitchen.
 * 
 * This class is a concrete implementation of the abstract Chef class. It contains a pointer to the next StationChef in the chain of responsibility.
 */
class StationChef : public Chef{
    protected:
        std::shared_ptr<StationChef> nextStationChef;

    public:
        /**
         * @brief Constructs a new StationChef object.
         * 
         * @param kitchen A pointer to the Kitchen object that the chef belongs to.
         * @param name The name of the chef.
         */
        StationChef(Kitchen* kitchen, std::string name);

        /**
         * @brief Destroys the StationChef object.
         */
        ~StationChef();

        /**
         * @brief Prepares the order by cooking the dish that the chef is responsible for.
         * 
         * This is a pure virtual function that must be implemented by the derived classes.
         * 
         * @param order A shared pointer to the Order object that contains the details of the order.
         */
        virtual void prepareOrder(std::shared_ptr<Order> order) = 0;

        /**
         * @brief Sets the next chef in the chain of responsibility.
         * 
         * This is a pure virtual function that must be implemented by the derived classes.
         */
        virtual void setNextChef() = 0;

        /**
         * @brief Returns a shared pointer to the next StationChef in the chain of responsibility.
         * 
         * @return A shared pointer to the next StationChef in the chain of responsibility.
         */
        std::shared_ptr<StationChef> getNextChef() const;
        
        /**
         * @brief Sets the next chef in the chain of responsibility.
         * 
         * @param nextChef A shared pointer to the next StationChef in the chain of responsibility.
         */
        void setNextChefAgain(std::shared_ptr<StationChef> nextChef);
};

#endif