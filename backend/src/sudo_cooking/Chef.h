#ifndef CHEF_H
#define CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "GameComponent.h"
#include "Kitchen.h"

class Chef : public GameComponent {
    protected:
        Kitchen *kitchen;
        std::string name;
    public:
        Chef(std::shared_ptr<Engine> engine, Kitchen *kitchen, std::string name);
        ~Chef();
        std::string getName() const;
        void setKitchen(Kitchen *kitchen);
        Kitchen* getKitchen() const;
        virtual void sendEvent() = 0;
        virtual void receiveEvent(std::string event) = 0;
};

#endif