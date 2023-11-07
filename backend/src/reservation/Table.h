#ifndef Table_H
#define Table_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "../customercare/Customer.h"

/**
 * @brief The Table class represents a table in the restaurant.
 */
class Table{
    private:
        int tableId; /**< The unique ID of the table. */
        int tableSize; /**< The number of seats at the table. */
        std::string section; /**< The section of the restaurant where the table is located. */
        bool isOccupied; /**< Whether the table is currently occupied by customers. */
        bool isReserved; /**< Whether the table is currently reserved for future customers. */
        bool markedForSlit; /**< Whether the table has been marked for splitting. */
        bool markedForMerge; /**< Whether the table has been marked for merging. */
        std::vector<std::shared_ptr<CustomerTemplate>> customers; /**< The customers currently seated at the table. */
        bool merged; /**< Whether the table has been merged with another table. */
        bool split; /**< Whether the table has been split into multiple tables. */
        
    public:
        static int tableCount; /**< The total number of tables in the restaurant. */

    public:
        /**
         * @brief Constructs a new Table object.
         * 
         * @param section The section of the restaurant where the table is located.
         * @param tableSize The number of seats at the table.
         */
        Table(std::string section, int tableSize);

        /**
         * @brief Destroys the Table object.
         */
        ~Table();

        /**
         * @brief Gets the unique ID of the table.
         * 
         * @return The table ID.
         */
        int getTableId();

        /**
         * @brief Gets the number of seats at the table.
         * 
         * @return The table size.
         */
        int getTableSize();

        /**
         * @brief Gets whether the table is currently occupied by customers.
         * 
         * @return True if the table is occupied, false otherwise.
         */
        bool getIsOccupied();

        /**
         * @brief Gets whether the table is currently reserved for future customers.
         * 
         * @return True if the table is reserved, false otherwise.
         */
        bool getIsReserved();

        /**
         * @brief Gets whether the table has been marked for splitting.
         * 
         * @return True if the table has been marked for splitting, false otherwise.
         */
        bool getMarkedForSplit();

        /**
         * @brief Gets whether the table has been marked for merging.
         * 
         * @return True if the table has been marked for merging, false otherwise.
         */
        bool getMarkedForMerge();

        /**
         * @brief Gets whether the table has been merged with another table.
         * 
         * @return True if the table has been merged, false otherwise.
         */
        bool getMerged();

        /**
         * @brief Gets whether the table has been split into multiple tables.
         * 
         * @return True if the table has been split, false otherwise.
         */
        bool getSplit();

        /**
         * @brief Gets the customers currently seated at the table.
         * 
         * @return A vector of shared pointers to CustomerTemplate objects.
         */
        std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();

        /**
         * @brief Gets the section of the restaurant where the table is located.
         * 
         * @return The section name.
         */
        std::string getSection();

        /**
         * @brief Sets whether the table has been merged with another table.
         * 
         * @param merged True if the table has been merged, false otherwise.
         */
        void setMerged(bool merged);

        /**
         * @brief Sets whether the table has been split into multiple tables.
         * 
         * @param split True if the table has been split, false otherwise.
         */
        void setSplit(bool split);

        /**
         * @brief Sets the section of the restaurant where the table is located.
         * 
         * @param section The section name.
         */
        void setSection(std::string section);

        /**
         * @brief Sets the unique ID of the table.
         * 
         * @param tableId The table ID.
         */
        void setTableId(int tableId);

        /**
         * @brief Sets the number of seats at the table.
         * 
         * @param tableSize The table size.
         */
        void setTableSize(int tableSize);

        /**
         * @brief Sets whether the table is currently occupied by customers.
         * 
         * @param isOccupied True if the table is occupied, false otherwise.
         */
        void setIsOccupied(bool isOccupied);

        /**
         * @brief Sets whether the table is currently reserved for future customers.
         * 
         * @param isReserved True if the table is reserved, false otherwise.
         */
        void setIsReserved(bool isReserved);

        /**
         * @brief Sets whether the table has been marked for splitting.
         * 
         * @param markedForSplit True if the table has been marked for splitting, false otherwise.
         */
        void setMarkedForSplit(bool markedForSplit);

        /**
         * @brief Sets whether the table has been marked for merging.
         * 
         * @param markedForMerge True if the table has been marked for merging, false otherwise.
         */
        void setMarkedForMerge(bool markedForMerge);

        /**
         * @brief Sets the customers currently seated at the table.
         * 
         * @param customers A vector of shared pointers to CustomerTemplate objects.
         */
        void setCustomers(std::vector<std::shared_ptr<CustomerTemplate>> customers);

        /**
         * @brief Adds a customer to the table.
         * 
         * @param customer A shared pointer to a CustomerTemplate object.
         */
        void addCustomer(std::shared_ptr<CustomerTemplate> customer);

        /**
         * @brief Removes a customer from the table.
         * 
         * @param customer A shared pointer to a CustomerTemplate object.
         */
        void removeCustomer(std::shared_ptr<CustomerTemplate> customer);

        /**
         * @brief Clears the table of all customers.
         */
        void clear();

        /**
         * @brief Seats a customer at the table.
         * 
         * @param customer A shared pointer to a CustomerTemplate object.
         */
        void sitCustomer(std::shared_ptr<CustomerTemplate> customer);
};

#endif