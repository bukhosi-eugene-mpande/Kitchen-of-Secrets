#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <vector>
#include <iostream>
#include <memory> 

#include "ReservationSystem.h"
#include "../customercare/CustomerTemplate.h"
class Reservation;
class Section;
class Host;

class Receptionist{

    private:
        std::shared_ptr<ReservationSystem> reservationSystem;
    public:
        Receptionist(std::shared_ptr<ReservationSystem> reservationSystem);
        ~Receptionist();
        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);
        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);
        std::shared_ptr<Host> createHost(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<CustomerTemplate> customer);
        std::shared_ptr<Reservation> createReservation(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);
};

#endif