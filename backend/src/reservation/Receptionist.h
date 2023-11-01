#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <vector>
#include <iostream>
#include <memory> 

#include "Reservation.h"
#include "../customercare/Customer.h"
#include "Host.h"
#include "ReservationSystem.h"

class Receptionist  {
    private:
        std::shared_ptr<ReservationSystem> reservationSystem;
        
    public:
        Receptionist(std::shared_ptr<ReservationSystem> reservationSystem);
        ~Receptionist();
        void requestReservation(std::shared_ptr<Customer> customer,std::string section);
        std::shared_ptr<Host> createHost(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<Customer> customer);
        std::shared_ptr<Reservation> createReservation(std::shared_ptr<Customer> customer, std::shared_ptr<Table> table);
};

#endif