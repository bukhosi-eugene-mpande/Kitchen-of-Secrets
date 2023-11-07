#ifndef GeneralTable_H
#define GeneralTable_H

#include <string>
#include <vector>
#include <memory>

#include "Table.h"

/**
 * @brief The GeneralTable class represents a general table in the restaurant.
 * 
 * This class inherits from the Table class and provides additional functionality
 * specific to general tables.
 */
class GeneralTable : public Table{

    public:
        /**
         * @brief Constructs a new GeneralTable object.
         * 
         */
        GeneralTable();

        /**
         * @brief Destroys the GeneralTable object.
         * 
         */
        ~GeneralTable();

};

#endif