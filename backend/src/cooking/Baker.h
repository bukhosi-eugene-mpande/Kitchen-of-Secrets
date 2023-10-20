#ifndef Baker_H
#define Baker_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class Baker : public Chef{
    private:
    std::string name;

    public:

        Baker(std::shared_ptr<Kitchen> management);

        ~Baker();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef(std::shared_ptr<Chef> nextChef);

};

#endif