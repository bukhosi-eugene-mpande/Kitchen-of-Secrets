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
        Management* management;
        
    public:

        DeputyHeadChef(Kitchen* kitchen);

        ~DeputyHeadChef();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef();

        void cancelOrder(std::shared_ptr<Order> order);

        void finishOrder(std::shared_ptr<Order> order);

        std::shared_ptr<Chef> getNextChef() const;

        Kitchen* getKitchen() const;

        void setManagement();

};

#endif