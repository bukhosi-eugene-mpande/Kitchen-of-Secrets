#ifndef Baker_H
#define Baker_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

class Baker : public StationChef{
    private:
    std::string name;

    public:

        Baker(Kitchen* Kitchen);

        ~Baker();

        void prepareOrder(std::shared_ptr<Order> order) override;

        void setNextChef() override;
        
};

#endif