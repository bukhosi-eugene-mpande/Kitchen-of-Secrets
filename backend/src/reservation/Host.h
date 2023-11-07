#ifndef SeatPlan_H
#define SeatPlan_H

#include <iostream>
#include <vector>
#include <memory>

#include "Reservation.h"

class Table;
class Section;
class Customer;

/**
 * @brief The Host class represents a restaurant host who is responsible for seating customers and taking them to their tables.
 */
class Host {
    private:
        std::shared_ptr<Section> section; /**< The section where the customer will be seated. */
        std::shared_ptr<Reservation> reservation; /**< The reservation for the customer. */
        std::shared_ptr<CustomerTemplate> customer; /**< The customer to be seated. */
    public:
        /**
         * @brief Constructs a new Host object.
         * 
         * @param section The section where the customer will be seated.
         * @param reservation The reservation for the customer.
         * @param customer The customer to be seated.
         */
        Host(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<CustomerTemplate> customer);

        /**
         * @brief Destroys the Host object.
         */
        ~Host();

        /**
         * @brief Seats the customer in the assigned section and table.
         */
        void seatCustomer();

        /**
         * @brief Gets the section where the customer will be seated.
         * 
         * @return The section where the customer will be seated.
         */
        std::shared_ptr<Section> getSection();

        /**
         * @brief Sets the section where the customer will be seated.
         * 
         * @param section The section where the customer will be seated.
         */
        void setSection(std::shared_ptr<Section> section);

        /**
         * @brief Gets the reservation for the customer.
         * 
         * @return The reservation for the customer.
         */
        std::shared_ptr<Reservation> getReservation();

        /**
         * @brief Sets the reservation for the customer.
         * 
         * @param reservation The reservation for the customer.
         */
        void setReservation(std::shared_ptr<Reservation> reservation);

        /**
         * @brief Gets the customer to be seated.
         * 
         * @return The customer to be seated.
         */
        std::shared_ptr<CustomerTemplate> getCustomer();

        /**
         * @brief Sets the customer to be seated.
         * 
         * @param customer The customer to be seated.
         */
        void setCustomer(std::shared_ptr<CustomerTemplate> customer);

        /**
         * @brief Takes the customer to their assigned table.
         */
        void takeCustomerToTable();

};

#endif