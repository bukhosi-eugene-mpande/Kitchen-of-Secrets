#ifndef HeadChef_H
#define HeadChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Management.h"
#include "Chef.h"

class HeadChef : public Chef{
    private:
        std::string name;
        Management* management;

    public:

        HeadChef(Kitchen* kitchen,Management* management);

        ~HeadChef();

        std::string getName() const;

        Kitchen* getKitchen() const;

        void goOnRounds();

        void handleComplaint();
};

#endif