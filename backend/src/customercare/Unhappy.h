#ifndef UNHAPPY_H
#define UNHAPPY_H

using namespace std;
#include <string>
#include "SatisfactionState.h"
class Unhappy : public SatisfactionState
{
public:
    Unhappy();
    ~Unhappy();
    void HelpMe();
    void setMood(SatisfactionState *contract);
    std::string getStateName();
};
#endif