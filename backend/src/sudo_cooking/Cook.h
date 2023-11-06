#ifndef COOK_H
#define COOK_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

class Cook : public StationChef { 
    public:
        Cook(std::shared_ptr<Engine> engine, Kitchen* kitchen);
        ~Cook();
        void prepareOrder(std::shared_ptr<Order> order) override;
        void setNextChef() override;
        virtual void sendEvent();
        virtual void receiveEvent(std::string event);
};

#endif