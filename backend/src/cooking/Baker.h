#ifndef BAKER_H
#define BAKER_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

class Baker : public StationChef {
    public:
        Baker(Kitchen* kitchen);

        ~Baker();

        void prepareOrder(std::shared_ptr<Order> order) override;
        
        void setNextChef() override;
};

#endif