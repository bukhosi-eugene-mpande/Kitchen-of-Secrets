#ifndef HeadChef_H
#define HeadChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class HeadChef : public Chef{
    private:
    std::string name;

    public:

        HeadChef(std::shared_ptr<Kitchen> kitchen);

        ~HeadChef();

        std::string getName() const;

        void setKitchen(std::shared_ptr<Kitchen> kitchen);

        std::shared_ptr<Kitchen> getKitchen() const;

        void goOnRounds();

        void handleComplaint();
};

#endif