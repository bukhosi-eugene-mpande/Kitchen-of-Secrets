#ifndef NEUTRAL_H
#define NEUTRAL_H

using namespace std;
#include <string>
#include "SatisfactionState.h"
class Neutral : public SatisfactionState
{
public:
    Neutral();
    ~Neutral();
    void HelpMe();
    void setMood(SatisfactionState *contract);
    std::string getStateName();
};
#endif