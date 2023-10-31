#ifndef FryChef_H
#define FryChef_H

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include "Kitchen.h"
#include "StationChef.h"

class FryChef : public StationChef{

    public:

        FryChef(Kitchen* Kitchen);

        ~FryChef();

        void setNextChef() override;

};

#endif