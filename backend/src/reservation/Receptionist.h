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

/**
 * @brief The Receptionist class represents a receptionist in a restaurant.
 * 
 * The Receptionist class is responsible for handling customer requests to be seated and to make reservations.
 * It also creates hosts and reservations for customers.
 */
class Receptionist{

    private:
        std::shared_ptr<ReservationSystem> reservationSystem; /**< A shared pointer to the reservation system. */
    public:
        /**
         * @brief Constructs a new Receptionist object.
         * 
         * @param reservationSystem A shared pointer to the reservation system.
         */
        Receptionist(std::shared_ptr<ReservationSystem> reservationSystem);

        /**
         * @brief Destroys the Receptionist object.
         */
        ~Receptionist();

        /**
         * @brief Handles a customer's request to be seated.
         * 
         * @param customer A shared pointer to the customer making the request.
         */
        void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);

        /**
         * @brief Handles a customer's request to make a reservation.
         * 
         * @param customer A shared pointer to the customer making the request.
         * @param section The section the customer wants to reserve a table in.
         */
        void requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section);

        /**
         * @brief Creates a new host for a customer.
         * 
         * @param section A shared pointer to the section the customer will be seated in.
         * @param reservation A shared pointer to the reservation the customer made.
         * @param customer A shared pointer to the customer.
         * @return A shared pointer to the new host.
         */
        std::shared_ptr<Host> createHost(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<CustomerTemplate> customer);

        /**
         * @brief Creates a new reservation for a customer.
         * 
         * @param customer A shared pointer to the customer making the reservation.
         * @param table A shared pointer to the table the customer wants to reserve.
         * @return A shared pointer to the new reservation.
         */
        std::shared_ptr<Reservation> createReservation(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);
};

#endif