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

        Cook(Kitchen* Kitchen);

        ~Cook();

        void setNextChef() override;

};

#endif