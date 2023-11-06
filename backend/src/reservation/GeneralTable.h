/**
 * @file GeneralTable.h
 * @brief Contains the declaration of the GeneralTable class, representing a general table in a restaurant.
 */

#ifndef GENERALTABLE_H
#define GENERALTABLE_H

#include <string>
#include <vector>
#include <memory>

#include "Table.h"

/**
 * @class GeneralTable
 * @brief Represents a general table in a restaurant.
 *
 * The GeneralTable class is a specific type of restaurant table typically found in general dining sections.
 */
class GeneralTable : public Table {
public:
    /**
     * @brief Constructor for the GeneralTable class.
     */
    GeneralTable();

    /**
     * @brief Destructor for the GeneralTable class.
     */
    ~GeneralTable();
};

#endif
