#ifndef HAPPY_H
#define HAPPY_H

using namespace std;
#include <string>
#include "SatisfactionState.h"
class Happy : public SatisfactionState
{
public:
    void HelpMe(Customer *Mood, std::string complaints);
    void timeLaps(Customer *Mood,std::string complaints);
    int getBill(int totalBill);
    std::string getStateName();
};
#endif