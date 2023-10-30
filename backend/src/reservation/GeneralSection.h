#ifndef GENERALSECTION_H
#define GENERALSECTION_H

#include "SeatingPlan.h"

class GeneralSection : public SeatingPlan {
 public: 
    GeneralSection();
    ~GeneralSection();
    void addReservation();
    void markTableOccupied();
    bool isTableAvailable();
};

#endif
