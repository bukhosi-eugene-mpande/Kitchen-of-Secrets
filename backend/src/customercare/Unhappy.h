#ifndef UNHAPPY_H
#define UNHAPPY_H

using namespace std;
#include <string>
#include "SatisfactionState.h"
#include "Customer.h"
#include <algorithm>
class Unhappy : public SatisfactionState
{
public:
    void HelpMe(Customer *Mood, std::string complaints);
    void timeLaps(Customer *Mood,std::string complaints);
    int getBill(int totalBill);
    std::string getStateName();
};
#endif