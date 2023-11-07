#ifndef PrivateTable_H
#define PrivateTable_H

#include "Table.h"

/**
 * @brief A class representing a private table that can be reserved by customers.
 * 
 * This class inherits from the Table class and adds functionality specific to private tables.
 */
class PrivateTable : public Table {
    public:
        /**
         * @brief Constructs a new PrivateTable object.
         * 
         * This constructor initializes the PrivateTable object with default values.
         */
        PrivateTable();

        /**
         * @brief Destroys the PrivateTable object.
         * 
         * This destructor cleans up any resources used by the PrivateTable object.
         */
        ~PrivateTable();
};

#endif