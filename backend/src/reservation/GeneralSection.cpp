#ifndef GENERALSECTION_CPP
#define GENERALSECTION_CPP

#include "GeneralSection.h"


#endif

GeneralSection::GeneralSection() : SeatingPlan() {}

GeneralSection::~GeneralSection() {}

//BRIDGE....do these belong here?
void GeneralSection::addReservation()
{
}

void GeneralSection::markTableOccupied()
{
}

bool GeneralSection::isTableAvailable()
{
    return false;
}
