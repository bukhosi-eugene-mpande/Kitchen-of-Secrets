#ifndef VERYUNHAPPY_H
#define VERYUNHAPPY_H

using namespace std;
#include <string>
#include "SatisfactionState.h"
class VeryUnhappy : public SatisfactionState
{
public:
    VeryUnhappy();
    ~VeryUnhappy();
    void HelpMe();
    void setMood(SatisfactionState *contract);
    std::string getStateName();
};
#endif