#ifndef Cook_H
#define Cook_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

class Cook : public StationChef{

    public:

        Cook(std::shared_ptr<Kitchen> kitchen);

        ~Cook();

        void setNextChef() override;

};

#endif