#ifndef Cook_H
#define Cook_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class Cook : public Chef{
    private:
    std::string name;

    public:

        Cook(std::shared_ptr<Kitchen> management);

        ~Cook();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef(std::shared_ptr<Chef> nextChef);

};

#endif