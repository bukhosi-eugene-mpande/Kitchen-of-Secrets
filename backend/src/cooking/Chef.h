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
        std::shared_ptr<Kitchen> kitchen;
        std::string name;
    public:
        Chef(std::shared_ptr<Engine> engine, std::shared_ptr<Kitchen> kitchen, std::string name);
        ~Chef();
        std::string getName() const;
        void setKitchen(std::shared_ptr<Kitchen> kitchen);
        std::shared_ptr<Kitchen> getKitchen() const;
};

#endif