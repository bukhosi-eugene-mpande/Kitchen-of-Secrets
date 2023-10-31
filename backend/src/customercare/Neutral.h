#ifndef NEUTRAL_H
#define NEUTRAL_H

using namespace std;
#include <string>
#include <algorithm>
#include "SatisfactionState.h"
class Neutral : public SatisfactionState
{
public:
    void HelpMe(Customer *Mood, std::string complaints);
    void timeLaps(Customer *Mood,std::string complaints);
    int getBill(int totalBill);
    std::string getStateName();
};
#endif