#ifndef StationChef_H
#define StationChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class StationChef : public Chef{
    private:
        std::shared_ptr<StationChef> nextStationChef;

    public:

        StationChef(std::string name,std::shared_ptr<Kitchen> kitchen);

        ~StationChef();

        virtual void prepareOrder(std::shared_ptr<Order> order) = 0;

        void setNextChef(std::shared_ptr<StationChef> nextStationChef);

        std::shared_ptr<StationChef> getNextChef() const;
        
};

#endif