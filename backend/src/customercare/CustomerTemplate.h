#ifndef CustomerTemplate_H
#define CustomerTemplate_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>

class SatisfactionState;

class CustomerTemplate{
    private:
        std::shared_ptr<SatisfactionState> Mood;

    public:
        CustomerTemplate();
        ~CustomerTemplate();
        std::shared_ptr<SatisfactionState> getMood();
        double calculateFinalBill(double bill);
        void setMood(std::shared_ptr<SatisfactionState> Mood);


};
#endif