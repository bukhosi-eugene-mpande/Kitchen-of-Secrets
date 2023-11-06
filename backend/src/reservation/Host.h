/**
 * @file Host.h
 * @brief Contains the declaration of the Host class, responsible for seating customers in a restaurant.
 */

#ifndef HOST_H
#define HOST_H

#include <iostream>
#include <vector>
#include <memory>

#include "Reservation.h"

class Table;
class Section;
class Customer;

/**
 * @class Host
 * @brief Represents a host responsible for seating customers in a restaurant.
 *
 * The Host class manages the process of assigning customers to tables in different sections based on reservations.
 */
class Host {
private:
    std::shared_ptr<Section> section; ///< The section where the host works.
    std::shared_ptr<Reservation> reservation; ///< The reservation for the customer.
    std::shared_ptr<CustomerTemplate> customer; ///< The customer to be seated.

public:
    /**
     * @brief Constructor for the Host class.
     *
     * @param section The section where the host works.
     * @param reservation The reservation for the customer.
     * @param customer The customer to be seated.
     */
    Host(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<CustomerTemplate> customer);

    /**
     * @brief Destructor for the Host class.
     */
    ~Host();

    /**
     * @brief Seat the customer in the restaurant.
     */
    void seatCustomer();

    /**
     * @brief Get the section where the host works.
     *
     * @return A shared pointer to the section.
     */
    std::shared_ptr<Section> getSection();

    /**
     * @brief Set the section where the host works.
     *
     * @param section A shared pointer to the section.
     */
    void setSection(std::shared_ptr<Section> section);

    /**
     * @brief Get the reservation for the customer.
     *
     * @return A shared pointer to the reservation.
     */
    std::shared_ptr<Reservation> getReservation();

    /**
     * @brief Set the reservation for the customer.
     *
     * @param reservation A shared pointer to the reservation.
     */
    void setReservation(std::shared_ptr<Reservation> reservation);

    /**
     * @brief Get the customer to be seated.
     *
     * @return A shared pointer to the customer.
     */
    std::shared_ptr<CustomerTemplate> getCustomer();

    /**
     * @brief Set the customer to be seated.
     *
     * @param customer A shared pointer to the customer.
     */
    void setCustomer(std::shared_ptr<CustomerTemplate> customer);

    /**
     * @brief Take the customer to the assigned table.
     */
    void takeCustomerToTable();
};

#endif
