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

    public:

        Chef(std::string name,std::shared_ptr<Kitchen> kitchen);

        ~Chef();

        std::string getName() const;

        void setKitchen(std::shared_ptr<Kitchen> kitchen);

        std::shared_ptr<Kitchen> getKitchen() const;

};

#endif