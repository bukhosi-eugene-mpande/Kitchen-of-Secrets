#include "Happy.h"
#include "UnHappy.h"

void Happy::HelpMe(Customer *Mood, std::string complaints){
    Mood->setMood(new Happy());
}
void Happy::timeLaps(Customer *Mood,std::string complaints){
    Mood->getComplaints()->push_back(complaints);
    Mood->setMood(new Unhappy());
}
int Happy::getBill(int totalBill){
    return 0.10 * totalBill;
}
std::string Happy::getStateName(){
    return "Happy";
}