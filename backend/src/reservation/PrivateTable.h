/**
 * @file PrivateTable.h
 * @brief Contains the declaration of the PrivateTable class, representing a private dining table in a restaurant.
 */

#ifndef PRIVATETABLE_H
#define PRIVATETABLE_H

#include "Table.h"

/**
 * @class PrivateTable
 * @brief Represents a private dining table in a restaurant.
 *
 * The PrivateTable class is responsible for managing private dining tables within a private dining section.
 */
class PrivateTable : public Table {
public:
    /**
     * @brief Constructor for the PrivateTable class.
     */
    PrivateTable();

    /**
     * @brief Destructor for the PrivateTable class.
     */
    ~PrivateTable();
};

#endif
