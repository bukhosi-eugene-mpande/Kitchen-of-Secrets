#ifndef HEAD_CHEF_H
#define HEAD_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

#include "../management/PlayerInteraction.h"

class HeadChef : public Chef {
    private:
        PlayerInteraction* management;

        std::string name;

    public:
        HeadChef(Kitchen* kitchen,PlayerInteraction* management);

        ~HeadChef();

        std::string getName() const;

        Kitchen* getKitchen() const;
        
        void goOnRounds();
};

#endif