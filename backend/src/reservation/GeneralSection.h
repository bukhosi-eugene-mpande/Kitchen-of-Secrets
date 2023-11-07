#ifndef GeneralSection_H
#define GeneralSection_H

#include "Section.h"
#include "GeneralTable.h"

/**
 * @brief The GeneralSection class represents a general section in a restaurant.
 * 
 * This class inherits from the Section class and provides additional functionality
 * specific to general sections.
 */
class GeneralSection : public Section{
    public: 
        /**
         * @brief Constructs a new GeneralSection object.
         * 
         * This constructor initializes the GeneralSection object with default values.
         */
        GeneralSection();

        /**
         * @brief Destroys the GeneralSection object.
         * 
         * This destructor cleans up any resources used by the GeneralSection object.
         */
        ~GeneralSection();
};

#endif
