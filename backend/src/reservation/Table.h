/**
 * @file Table.h
 * @brief Contains the declaration of the Table class, representing a table in the restaurant.
 */

#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "../customercare/Customer.h"

/**
 * @class Table
 * @brief Represents a table in the restaurant with occupancy and reservation status.
 *
 * The Table class is responsible for managing the status and occupancy of a table in the restaurant.
 */
class Table {
private:
    int tableId; /**< The unique ID of the table. */
    int tableSize; /**< The size or capacity of the table. */
    std::string section; /**< The section to which the table belongs. */
    bool isOccupied; /**< Indicates whether the table is currently occupied by customers. */
    bool isReserved; /**< Indicates whether the table is reserved for upcoming customers. */
    bool markedForSplit; /**< Indicates whether the table is marked for splitting. */
    bool markedForMerge; /**< Indicates whether the table is marked for merging with another table. */
    std::vector<std::shared_ptr<CustomerTemplate>> customers; /**< A vector of shared pointers to customers at this table. */
    bool merged; /**< Indicates whether this table has been merged with another table. */
    bool split; /**< Indicates whether this table has been split into multiple tables. */

public:
    /**
     * @brief Constructor for the Table class.
     * @param section The section to which the table belongs.
     * @param tableSize The size or capacity of the table.
     */
    Table(std::string section, int tableSize);

    /**
     * @brief Destructor for the Table class.
     */
    ~Table();

    /**
     * @brief Get the unique ID of the table.
     * @return The table's unique ID.
     */
    int getTableId();

    /**
     * @brief Get the size or capacity of the table.
     * @return The table's size or capacity.
     */
    int getTableSize();

    /**
     * @brief Check if the table is currently occupied by customers.
     * @return `true` if the table is occupied, otherwise `false`.
     */
    bool getIsOccupied();

    /**
     * @brief Check if the table is reserved for upcoming customers.
     * @return `true` if the table is reserved, otherwise `false`.
     */
    bool getIsReserved();

    /**
     * @brief Check if the table is marked for splitting.
     * @return `true` if the table is marked for splitting, otherwise `false`.
     */
    bool getMarkedForSplit();

    /**
     * @brief Check if the table is marked for merging with another table.
     * @return `true` if the table is marked for merging, otherwise `false`.
     */
    bool getMarkedForMerge();

    /**
     * @brief Check if the table has been merged with another table.
     * @return `true` if the table has been merged, otherwise `false`.
     */
    bool getMerged();

    /**
     * @brief Check if the table has been split into multiple tables.
     * @return `true` if the table has been split, otherwise `false`.
     */
    bool getSplit();
        std::vector<std::shared_ptr<CustomerTemplate>> getCustomers();
        std::string getSection();
        void setMerged(bool merged);
        void setSplit(bool split);
        void setSection(std::string section);
        void setTableId(int tableId);
        void setTableSize(int tableSize);
        void setIsOccupied(bool isOccupied);
        void setIsReserved(bool isReserved);
        void setMarkedForSplit(bool markedForSplit);
        void setMarkedForMerge(bool markedForMerge);
        void setCustomers(std::vector<std::shared_ptr<CustomerTemplate>> customers);
        void addCustomer(std::shared_ptr<CustomerTemplate> customer);
        void removeCustomer(std::shared_ptr<CustomerTemplate> customer);
        void clear();
        void sitCustomer(std::shared_ptr<CustomerTemplate> customer);
};

#endif