#ifndef PRIVATESECTION_CPP
#define PRIVATESECTION_CPP

#include "PrivateSection.h"

PrivateSection::PrivateSection() : SeatingPlan() {}

PrivateSection::~PrivateSection(){}

//bridge design pattern -- do these below get implemented?
void PrivateSection::addReservation()
{

}

void PrivateSection::markTableOccupied()
{

}

bool PrivateSection::isTableAvailable()
{
    return false;
}

#endif