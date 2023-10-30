#ifndef PRIVATESECTION_H
#define PRIVATESECTION_H

#include "SeatingPlan.h"

class PrivateSection : public SeatingPlan {
 public: 
    PrivateSection();
    ~PrivateSection();
    void addReservation();
    void markTableOccupied();
    bool isTableAvailable();
};

#endif
