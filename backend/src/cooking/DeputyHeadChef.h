#ifndef DeputyHeadChef_H
#define DeputyHeadChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"
#include "Chef.h"

class Management;


class DeputyHeadChef : public StationChef {
    private: 
        PlayerInteraction* management;
        bool flag;
        
    public:

        DeputyHeadChef(Kitchen* kitchen);

        ~DeputyHeadChef();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef();

        void cancelOrder(std::shared_ptr<Order> order);

        void finishOrder(std::shared_ptr<Order> order);
        
        Kitchen* getKitchen() const;

        void setManagement();

};

#endif