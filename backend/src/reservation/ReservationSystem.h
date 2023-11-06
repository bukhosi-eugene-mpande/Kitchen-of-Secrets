/**
 * @file ReservationSystem.h
 * @brief Contains the declaration of the ReservationSystem class, managing restaurant reservations.
 */

#ifndef RESERVATION_SYSTEM_H
#define RESERVATION_SYSTEM_H

#include <vector>
#include <memory>
#include <iostream>

class PrivateSection;
class GeneralSection;
class Host;
class CustomerTemplate;

/**
 * @class ReservationSystem
 * @brief Manages restaurant reservations, sections, and customer records.
 *
 * The ReservationSystem class is responsible for managing reservations, sections, and customer records within the restaurant.
 */
class ReservationSystem {
private:
    std::shared_ptr<PrivateSection> privateSection; /**< A shared pointer to the private section in the restaurant. */
    std::shared_ptr<GeneralSection> generalSection; /**< A shared pointer to the general section in the restaurant. */
    std::vector<std::shared_ptr<CustomerTemplate>> garbage; /**< A vector of shared pointers to customer records to be cleared. */

public:
    /**
     * @brief Constructor for the ReservationSystem class.
     */
    ReservationSystem();

    /**
     * @brief Destructor for the ReservationSystem class.
     */
    ~ReservationSystem();

    /**
     * @brief Get a shared pointer to the private section.
     * @return A shared pointer to the private section.
     */
    std::shared_ptr<Section> getPrivateSection();

    /**
     * @brief Get a shared pointer to the general section.
     * @return A shared pointer to the general section.
     */
    std::shared_ptr<Section> getGeneralSection();

    /**
     * @brief Get a vector of shared pointers to customer records.
     * @return A vector of shared pointers to customer records.
     */
    std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();

    /**
     * @brief Clear out a table after it is no longer in use.
     * @param table A shared pointer to the table to be cleared.
     */
    void clearOutTable(std::shared_ptr<Table> table);
};

#endif
