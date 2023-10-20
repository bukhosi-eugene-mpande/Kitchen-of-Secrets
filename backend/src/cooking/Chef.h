#ifndef Chef_H
#define Chef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"

class Chef {
    protected:
    std::shared_ptr<Kitchen> kitchen;
    std::string name;
    std::shared_ptr<Chef> nextChef;

    public:

        Chef(std::string name,std::shared_ptr<Kitchen> kitchen);

        ~Chef();

        virtual void prepareOrder(std::shared_ptr<Order> order)=0;

        std::string getName() const;

        void setNextChef(std::shared_ptr<Chef> nextChef);
        
};

#endif