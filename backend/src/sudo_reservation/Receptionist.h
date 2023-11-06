#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "backend/src/management/GameComponent.h"

#include <vector>
#include <iostream>
#include <memory> 

class ReservationSystem;
class Reservation;
class CustomerTemplate;
class Section;
class Host;

class Receptionist : public GameComponent {
    private:
        std::shared_ptr<ReservationSystem> reservationSystem;
    public:
        Receptionist(std::shared_ptr<Engine> engine, std::shared_ptr<ReservationSystem> reservationSystem);
        ~Receptionist();
        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);
        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);
        std::shared_ptr<Host> createHost(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<CustomerTemplate> customer);
        std::shared_ptr<Reservation> createReservation(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);
        virtual void sendEvent();
        virtual void receiveEvent(std::string event);
};

#endif