#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerCareSystem.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class SatisfactionState;

class Customer: public CustomerCareSystem
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