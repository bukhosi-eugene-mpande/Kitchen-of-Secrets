#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>
#include <memory> 
#include <iostream>

class PrivateSection;
class GeneralSection;
class Host;
class CustomerTemplate;

/**
 * @brief The ReservationSystem class represents a reservation system for a restaurant.
 */
class ReservationSystem {
    private:
        std::shared_ptr<PrivateSection> privateSection; /**< A shared pointer to the private section of the restaurant. */
        std::shared_ptr<GeneralSection> generalSection; /**< A shared pointer to the general section of the restaurant. */
        std::vector<std::shared_ptr<CustomerTemplate>> garbage; /**< A vector of shared pointers to customers who have left the restaurant. */
    public:
        /**
         * @brief Constructs a new ReservationSystem object.
         */
        ReservationSystem();

        /**
         * @brief Destroys the ReservationSystem object.
         */
        ~ReservationSystem();

        /**
         * @brief Returns a shared pointer to the private section of the restaurant.
         * @return A shared pointer to the private section of the restaurant.
         */
        std::shared_ptr<Section> getPrivateSection();

        /**
         * @brief Returns a shared pointer to the general section of the restaurant.
         * @return A shared pointer to the general section of the restaurant.
         */
        std::shared_ptr<Section> getGeneralSection();

        /**
         * @brief Returns a vector of shared pointers to customers who have left the restaurant.
         * @return A vector of shared pointers to customers who have left the restaurant.
         */
        std::vector<std::shared_ptr<CustomerTemplate>>  getCustomers();

        /**
         * @brief Clears out the table by removing all customers from it.
         * @param table A shared pointer to the table to be cleared out.
         */
        void clearOutTable(std::shared_ptr<Table> table);
};

#endif
