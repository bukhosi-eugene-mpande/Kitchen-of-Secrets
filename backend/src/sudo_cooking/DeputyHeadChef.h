#ifndef DeputyHeadChef_H
#define DeputyHeadChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class Management;

class DeputyHeadChef : public StationChef {
    private: 
        Management* management;
        bool flag;
        
    public:

        DeputyHeadChef(std::shared_ptr<Engine> engine, Kitchen* kitchen);

        ~DeputyHeadChef();

        void prepareOrder(std::shared_ptr<Order> order) override;

        void setNextChef() override;

        void cancelOrder(std::shared_ptr<Order> order);

        void finishOrder(std::shared_ptr<Order> order);
        
        Kitchen* getKitchen() const;

        void setManagement();

        virtual void sendEvent();
        virtual void receiveEvent(std::string event);

};

#endif