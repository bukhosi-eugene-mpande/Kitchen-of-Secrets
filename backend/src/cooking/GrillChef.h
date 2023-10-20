#ifndef GrillChef_H
#define GrillChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class GrillChef : public Chef{
    private:
    std::string name;

    public:

        GrillChef(std::shared_ptr<Kitchen> management);

        ~GrillChef();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef(std::shared_ptr<Chef> nextChef);

};

#endif