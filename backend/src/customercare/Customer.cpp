#include "Customer.h"
#include "Happy.h"

Customer::Customer(){
    this->Mood = new Happy();
    complaints = new std::vector<std::string>();
    this->totalBill= 0;
}

Customer::~Customer(){
    delete Mood;
    delete complaints;
}

void Customer::setTotalBill(int totalBill){
 this->totalBill=totalBill;
}

int Customer::getTotalBill(){
    return this->totalBill;
}

void Customer::setMood(SatisfactionState* Mood){
notify();
this->Mood=Mood;
}

SatisfactionState *Customer::getMood(){
return this->Mood;
}

void Customer::helpMe(){
    Mood->HelpMe(this,"waiting too long");
}

void Customer::timeLaps(){
    Mood->timeLaps(this,"waiting too long");
}
int Customer::getBill(int Bill){
 return Mood->getBill(Bill);
}

std::vector<std::string> *Customer::getComplaints(){
return this->complaints;
}



string Customer::toString(){
    std::stringstream ss;

    ss << "State: " << Mood->getStateName() << std::endl;

   
    ss << "complaints:" << std::endl;
    for (const auto &complaints : *complaints)
    {
        ss << complaints << std::endl;
    }

    return ss.str();
}