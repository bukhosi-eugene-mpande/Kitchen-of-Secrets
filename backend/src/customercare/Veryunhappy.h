#ifndef VERYUNHAPPY_H
#define VERYUNHAPPY_H

using namespace std;
#include <string>
#include "SatisfactionState.h"
class VeryUnhappy : public SatisfactionState
{
public:
    void HelpMe(Customer *Mood, std::string complaints);
    void timeLaps(Customer *Mood,std::string complaints);
    int getBill(int totalBill);
    std::string getStateName();
};
#endif