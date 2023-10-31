#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "SatisfactionState.h"
#include <string>
#include <vector>


class Customer
{
private:
    SatisfactionState * mood;
    std::vector<std::string> *complaints;
public:
    Customer();
    ~Customer();
    SatisfactionState* getMood();
    void setMood(SatisfactionState* Mood);
    void helpMe();
    string toString();
    void sendNotification();
    void recieveNotification();
    void checkIn();
    void checkOut();
    void cancelOrder();
    std::vector<std::string> *getComplaints();
    void addComplaints(std::string complaints);
    
};
#endif