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

        HeadChef(std::shared_ptr<Kitchen> management);

        ~HeadChef();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef(std::shared_ptr<Chef> nextChef);

        void cancelOrder(std::shared_ptr<Order> order);

        void finishOrder(std::shared_ptr<Order> order);

};

#endif