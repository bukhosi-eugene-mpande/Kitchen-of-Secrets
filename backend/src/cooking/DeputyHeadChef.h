#ifndef DeputyHeadChef_H
#define DeputyHeadChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class DeputyHeadChef : public Chef {
    private: 
        std::shared_ptr<Chef> nextChef;

    public:

        DeputyHeadChef(std::shared_ptr<Kitchen> kitchen);

        ~DeputyHeadChef();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef(std::shared_ptr<Chef> nextChef);

        void cancelOrder(std::shared_ptr<Order> order);

        void finishOrder(std::shared_ptr<Order> order);

};

#endif