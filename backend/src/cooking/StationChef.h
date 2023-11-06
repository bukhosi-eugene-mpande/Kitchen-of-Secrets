#ifndef STATION_CHEF_H
#define STATION_CHEF_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class StationChef : public Chef{
    protected:
        std::shared_ptr<StationChef> nextStationChef;

    public:
        StationChef(Kitchen* kitchen, std::string name);

        ~StationChef();

        virtual void prepareOrder(std::shared_ptr<Order> order) = 0;

        virtual void setNextChef() = 0;

        std::shared_ptr<StationChef> getNextChef() const;
        
        void setNextChefAgain(std::shared_ptr<StationChef> nextChef);
};

#endif