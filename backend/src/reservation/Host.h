#ifndef SeatPlan_H
#define SeatPlan_H

#include <iostream>
#include <vector>
#include <memory>

#include "Reservation.h"

class Table;
class Section;
class Customer;

class Host {
    private:
        std::shared_ptr<Section> section;
        std::shared_ptr<Reservation> reservation;
        std::shared_ptr<CustomerTemplate> customer;
    public:
        Host(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<CustomerTemplate> customer);
        ~Host();
        void seatCustomer();
        std::shared_ptr<Section> getSection();
        void setSection(std::shared_ptr<Section> section);
        std::shared_ptr<Reservation> getReservation();
        void setReservation(std::shared_ptr<Reservation> reservation);
        std::shared_ptr<CustomerTemplate> getCustomer();
        void setCustomer(std::shared_ptr<CustomerTemplate> customer);
        void takeCustomerToTable();

};

#endif