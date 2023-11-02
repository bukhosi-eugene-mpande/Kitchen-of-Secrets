#include "Unhappy.h"
#include "VeryUnhappy.h"
#include "Neutral.h"


void Unhappy::HelpMe(Customer *Mood, std::string complaints){
    std::vector<std::string> *complaint = Mood->getComplaints();
    auto it = std::find(complaint->begin(), complaint->end(), complaints);
    if (it != complaint->end())
    {
        complaint->erase(it);
    }
    Mood->setMood(new Neutral());

}

void Unhappy::timeLaps(Customer *Mood, std::string complaints){
    Mood->getComplaints()->clear();
    Mood->setMood(new VeryUnhappy());
}
int Unhappy::getBill(int totalBill){
    return 0;
}
std::string Unhappy::getStateName(){
    return "Unhappy";
}