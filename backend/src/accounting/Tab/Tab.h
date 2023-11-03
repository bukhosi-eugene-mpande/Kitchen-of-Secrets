#ifndef TAB_H
#define TAB_H

#include "TabState.h"
#include "backend/src/management/GameComponent.h"
#include "backend/src/cooking/Order.h"

class Tab : GameComponent {
    private:
        /**
         * @brief 
         * 
         */
        std::shared_ptr<TabState> state;

        /**
         * @brief 
         * 
         */
        double tabTotal;

        /**
         * @brief 
         * 
         */
        std::vector<std::shared_ptr<Order>> orderedItems;

    public:
        /**
         * @brief Construct a new Tab object
         * 
         * @param engine 
         */
        Tab(std::shared_ptr<Engine> engine);

        /**
         * @brief 
         * 
         * @return json 
         */
        json closeTab();

        /**
         * @brief Get the Tab Total object
         * 
         * @return double 
         */
        double getTabTotal();

        /**
         * @brief 
         * 
         * @param cost 
         * @return json 
         */
        json addOrderCost(double cost);

        /**
         * @brief Set the State object
         * 
         * @param state 
         */
        void setState(std::shared_ptr<TabState> state);

        /**
         * @brief 
         * 
         * @param orderedItems 
         * @return double 
         */
        double calculateOrderCost(const std::vector<std::shared_ptr<Order>> orderedItems);

        /**
         * @brief Get the Ordered Items object
         * 
         * @return std::vector<std::shared_ptr<Order>> 
         */
        std::vector<std::shared_ptr<Order>> getOrderedItems();

        /**
         * @brief 
         * 
         */
        virtual void sendEvent();

        /**
         * @brief 
         * 
         * @param event 
         */
        virtual void receiveEvent(std::string event);

};

#endif