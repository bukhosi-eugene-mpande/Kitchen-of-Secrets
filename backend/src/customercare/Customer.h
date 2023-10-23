#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "SatisfactionState.h"
#include <string>
#include <vector>
class Customer
{
private:
    SatisfactionState * mood;
    vector<string> complaints;
public:
    Customer();
    ~Customer();
    SatisfactionState* getMood();
    void setMood(SatisfactionState* Mood);
    void helpMe();
    void directMe();
    string toString();
    void sendNotification();
    void recieveNotification();
    void checkIn();
    void checkOut();
    void cancelOrder();
    vector<string> getComplaints();
    void setComplaints(vector<string> complaints);
    
};
#endif