/**
 * @file PrivateSection.h
 * @brief Contains the declaration of the PrivateSection class, representing a private dining section in a restaurant.
 */

#ifndef PRIVATESECTION_H
#define PRIVATESECTION_H

#include "Section.h"
#include "PrivateTable.h"

/**
 * @class PrivateSection
 * @brief Represents a private dining section in a restaurant.
 *
 * The PrivateSection class is responsible for managing the private dining area of a restaurant, which includes private tables.
 */
class PrivateSection : public Section {
public:
    /**
     * @brief Constructor for the PrivateSection class.
     */
    PrivateSection();

    /**
     * @brief Destructor for the PrivateSection class.
     */
    ~PrivateSection();
};

#endif
