#ifndef DeputyHeadChef_H
#define DeputyHeadChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class Management;

class DeputyHeadChef : public Chef {
    private: 
        std::shared_ptr<Chef> nextChef;
        std::shared_ptr<Management> management;

    public:

        DeputyHeadChef(std::shared_ptr<Kitchen> kitchen,std::shared_ptr<Management> management);

        ~DeputyHeadChef();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef();

        void cancelOrder(std::shared_ptr<Order> order);

        void finishOrder(std::shared_ptr<Order> order);

        std::shared_ptr<Chef> getNextChef() const;

};

#endif