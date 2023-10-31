#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "SatisfactionState.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>



class Customer
{
private:
    SatisfactionState *Mood;
    std::vector<std::string> *complaints;
    int totalBill;
public:
    Customer();
    ~Customer();
    SatisfactionState* getMood();
    void setTotalBill(int totalBill);
    int getTotalBill();
    void setMood(SatisfactionState* Mood);
    SatisfactionState *getMood();
    void helpMe();
    void timeLaps();
    int getBill(int Bill);
    std::vector<std::string> *getComplaints();
    void sendNotification();
    void receiveNotification();
    void checkOut();
    void cancelOrder();
   string toString();
};
#endif