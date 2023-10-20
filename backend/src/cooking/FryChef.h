#ifndef FryChef_H
#define FryChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "Chef.h"

class FryChef : public Chef{
    private:
    std::string name;

    public:

        FryChef(std::shared_ptr<Kitchen> management);

        ~FryChef();

        void prepareOrder(std::shared_ptr<Order> order);

        void setNextChef(std::shared_ptr<Chef> nextChef);

};

#endif