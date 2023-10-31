#ifndef Chef_H
#define Chef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"

class Chef {
    protected:
        Kitchen* kitchen;
        std::string name;

    public:

        Chef(std::string name,Kitchen* kitchen);

        ~Chef();

        std::string getName() const;

        void setKitchen(Kitchen* kitchen);

        Kitchen* getKitchen() const;

};

#endif