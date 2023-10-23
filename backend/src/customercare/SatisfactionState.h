#ifndef SATISFACTIONSTATE_H
#define SATISFACTIONSTATE_H

using namespace std;
#include <string>

class SatisfactionState
{
public:
    SatisfactionState();
    ~SatisfactionState();
    void HelpMe();
    SatisfactionState *getMood();
    void setMood(SatisfactionState *contract);
    virtual std::string getStateName() = 0;
};
#endif