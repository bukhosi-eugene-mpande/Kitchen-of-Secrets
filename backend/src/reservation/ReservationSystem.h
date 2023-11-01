#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>
#include <memory> 
#include <iostream>

#include "PrivateSection.h"
#include "GeneralSection.h"
#include "Host.h"

class ReservationSystem {
    private:
        std::shared_ptr<PrivateSection> privateSection;
        std::shared_ptr<GeneralSection> generalSection;

    public:
        ReservationSystem();
        ~ReservationSystem();
        std::shared_ptr<PrivateSection> getPrivateSection();
        std::shared_ptr<GeneralSection> getGeneralSection();
        std::vector<std::shared_ptr<Customer>> getCustomers();
        
};

#endif
