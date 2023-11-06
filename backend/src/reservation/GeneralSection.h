/**
 * @file GeneralSection.h
 * @brief Contains the declaration of the GeneralSection class, a specific type of restaurant section.
 */

#ifndef GENERALSECTION_H
#define GENERALSECTION_H

#include "Section.h"
#include "GeneralTable.h"

/**
 * @class GeneralSection
 * @brief Represents a general section in a restaurant.
 *
 * The GeneralSection class is a specific type of restaurant section that contains general tables.
 */
class GeneralSection : public Section {
public:
    /**
     * @brief Constructor for the GeneralSection class.
     */
    GeneralSection();

    /**
     * @brief Destructor for the GeneralSection class.
     */
    ~GeneralSection();
};

#endif
