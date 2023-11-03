#ifndef FRY_CHEF_H
#define FRY_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

class FryChef : public StationChef{
    public:
        FryChef(std::shared_ptr<Engine> engine, Kitchen* kitchen);
        ~FryChef();
        void prepareOrder(std::shared_ptr<Order> order) override;
        void setNextChef() override;
        virtual void sendEvent();
        virtual void receiveEvent(std::string event);
};

#endif