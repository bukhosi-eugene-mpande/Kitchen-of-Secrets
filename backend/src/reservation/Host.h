#ifndef SeatPlan_H
#define SeatPlan_H

#include <iostream>
#include <vector>
#include <memory>

#include "Table.h"
#include "Section.h"
#include "Reservation.h"
#include "../customercare/Customer.h"

class Host {
    private:
        std::shared_ptr<Section> section;
        std::shared_ptr<Reservation> reservation;
        std::shared_ptr<Customer> customer;
    public:
        Host(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<Customer> customer);
        ~Host();
        std::shared_ptr<Section> getSection();
        void setSection(std::shared_ptr<Section> section);
        std::shared_ptr<Reservation> getReservation();
        void setReservation(std::shared_ptr<Reservation> reservation);
        std::shared_ptr<Customer> getCustomer();
        void setCustomer(std::shared_ptr<Customer> customer);
        void takeCustomerToTable();

};

#endif