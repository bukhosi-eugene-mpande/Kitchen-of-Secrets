#ifndef HEAD_CHEF_H
#define HEAD_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "../sudo_management/Management.h"
#include "Chef.h"

class HeadChef : public Chef {
    private:
        std::string name;
        std::shared_ptr<Management> management;
    public:
        HeadChef(std::shared_ptr<Engine> engine, std::shared_ptr<Kitchen> kitchen, std::string name, std::shared_ptr<Management> management);
        ~HeadChef();
        std::string getName() const;
        std::shared_ptr<Kitchen> getKitchen() const;
        void goOnRounds();
<<<<<<< HEAD:backend/src/cooking/HeadChef.h
        void handleComplaint();
        virtual void sendEvent();
        virtual void receiveEvent(std::string event);
=======

>>>>>>> kitchen-Intergration:backend/src/sudo_cooking/HeadChef.h
};

#endif