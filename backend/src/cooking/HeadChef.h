#ifndef HEAD_CHEF_H
#define HEAD_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Management.h"
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
        void handleComplaint();
};

#endif