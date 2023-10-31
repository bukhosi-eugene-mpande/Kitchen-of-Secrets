#ifndef SATISFACTIONSTATE_H
#define SATISFACTIONSTATE_H

using namespace std;
#include <string>
#include "Customer.h"
class SatisfactionState
{
public:
    virtual void HelpMe(Customer *Mood,std::string complaints)=0;
    virtual void timeLaps(Customer *Mood,std::string complaints)=0;
    virtual int getBill(int totalBill)=0;
    virtual std::string getStateName() = 0;
};
#endif