#ifndef PrivateSection_H
#define PrivateSection_H

#include "Section.h"
#include "PrivateTable.h"

/**
 * @brief The PrivateSection class represents a private section in a restaurant.
 * 
 * This class inherits from the Section class and provides additional functionality
 * specific to private sections.
 */
class PrivateSection : public Section{
    public: 
        /**
         * @brief Constructs a new PrivateSection object.
         * 
         * This constructor initializes the private section with default values.
         */
        PrivateSection();

        /**
         * @brief Destroys the PrivateSection object.
         * 
         * This destructor cleans up any resources used by the private section.
         */
        ~PrivateSection();
};

#endif
