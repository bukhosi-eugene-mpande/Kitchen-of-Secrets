#ifndef GrillChef_H
#define GrillChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

class GrillChef : public StationChef{

    public:

        GrillChef(Kitchen* kitchen);

        ~GrillChef();

        void setNextChef() override;

};

#endif