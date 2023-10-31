#include "Neutral.h"
#include "Happy.h"
#include "Unhappy.h"

void Neutral::HelpMe(Customer *Mood, std::string complaints){
    Mood->getComplaints()->clear();
    Mood->setMood(new Happy());
}

void Neutral::timeLaps(Customer *Mood,std::string complaints){
    Mood->getComplaints()->push_back(complaints);
    Mood->setMood(new Unhappy());
}

int Neutral::getBill(int totalBill){
    return 0.10 * totalBill;
}

std::string Neutral::getStateName(){
    return"Neutral";
}