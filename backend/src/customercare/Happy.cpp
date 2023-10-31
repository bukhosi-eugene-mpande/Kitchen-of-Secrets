#include "Happy.h"
#include "Neutral.h"

void Happy::HelpMe(Customer *Mood, std::string complaints){
}
void Happy::timeLaps(Customer *Mood,std::string complaints){
    Mood->getComplaints()->push_back(complaints);
    Mood->setMood(new Neutral());
}
int Happy::getBill(int totalBill){
    return 0.10 * totalBill;
}
std::string Happy::getStateName(){
    return "Happy";
}