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

        Baker(std::shared_ptr<Kitchen> management);

        ~Baker();

        void setNextChef() override;
        
};

#endif