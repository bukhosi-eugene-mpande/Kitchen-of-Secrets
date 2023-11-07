#ifndef Reservation_H
#define Reservation_H

#include <string>
#include <vector>
#include <memory>

class CustomerTemplate;
class Table;

/**
 * @brief The Reservation class represents a reservation made by a customer for a table.
 */
class Reservation {
    private:
    std::shared_ptr<CustomerTemplate> customer; /**< The customer who made the reservation. */
    std::shared_ptr<Table> table; /**< The table reserved by the customer. */

    public:
        /**
         * @brief Constructs a new Reservation object.
         * 
         * @param customer The customer who made the reservation.
         * @param table The table reserved by the customer.
         */
        Reservation(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table);

        /**
         * @brief Destroys the Reservation object.
         */
        ~Reservation();

        /**
         * @brief Returns the customer who made the reservation.
         * 
         * @return std::shared_ptr<CustomerTemplate> The customer who made the reservation.
         */
        std::shared_ptr<CustomerTemplate> getCustomer();

        /**
         * @brief Returns the table reserved by the customer.
         * 
         * @return std::shared_ptr<Table> The table reserved by the customer.
         */
        std::shared_ptr<Table> getTable();

};

#endif