#ifndef HAPPY_H
#define HAPPY_H

using namespace std;
#include <string>
#include "SatisfactionState.h"
class Happy : public SatisfactionState
{
public:
    Happy();
    ~Happy();
    void HelpMe();
    void setMood(SatisfactionState *contract);
    std::string getStateName();
};
#endif