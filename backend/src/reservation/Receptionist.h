/**
 * @file Receptionist.h
 * @brief Contains the declaration of the Receptionist class, responsible for managing reservations and customer seating.
 */

#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <vector>
#include <iostream>
#include <memory> 

#include "ReservationSystem.h"
#include "../customercare/CustomerTemplate.h"

/**
 * @class Receptionist
 * @brief Manages reservations and customer seating in a restaurant.
 *
 * The Receptionist class is responsible for handling reservation requests, customer seating, and creating hosts for customer service.
 */
class Receptionist {
private:
    std::shared_ptr<ReservationSystem> reservationSystem;

public:
    /**
     * @brief Constructor for the Receptionist class.
     * @param reservationSystem A shared pointer to the reservation system used by the receptionist.
     */
    Receptionist(std::shared_ptr<ReservationSystem> reservationSystem);

    /**
     * @brief Destructor for the Receptionist class.
     */
    ~Receptionist();

    /**
     * @brief Request to seat a customer at an available table.
     * @param customer A shared pointer to the customer to be seated.
     */
    void requestToBeSeated(std::shared_ptr<CustomerTemplate> customer);

    /**
     * @brief Request a reservation for a customer in a specific section.
     * @param customer A shared pointer to the customer requesting the reservation.
     * @param section A string specifying the desired section for the reservation.
     */
    void requestReservation(std::shared_ptr<CustomerTemplate> customer, std::string section);

    /**
     * @brief Create a host to manage the seating of a customer with a reservation.
     * @param section A shared pointer to the section where the reservation is made.
     * @param reservation A shared pointer to the reservation for the customer.
     * @param customer A shared pointer to the customer with a reservation.
     * @return A shared pointer to the created host.
     */
    std::shared_ptr<Host> createHost(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<CustomerTemplate> customer);

    /**
     * @brief Create a reservation for a customer at a specific table.
     * @param customer A shared pointer to the customer making the reservation.
     * @param table A shared pointer to the table reserved for the customer.
     * @return A shared pointer to the created reservation.
     */
    std::shared_ptr<Reservation> createReservation(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);
};

#endif
