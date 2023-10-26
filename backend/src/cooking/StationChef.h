#ifndef StationChef_H
#define StationChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class StationChef : public Chef{
    protected:
        std::shared_ptr<Chef> nextStationChef;

    public:

        StationChef(std::string name,std::shared_ptr<Kitchen> kitchen);

        ~StationChef();

        void prepareOrder(std::shared_ptr<Order> order) override;

        virtual void setNextChef() = 0;

        std::shared_ptr<Chef> getNextChef() const;
        
};

#endif