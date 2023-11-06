/**
 * @file Section.h
 * @brief Contains the declaration of the Section class, representing a section of the restaurant.
 */

#ifndef SECTION_H
#define SECTION_H

#include <string>
#include <vector>
#include <memory>

class Table;
class Customer;

/**
 * @class Section
 * @brief Represents a section of the restaurant with tables and customers.
 *
 * The Section class is responsible for managing tables and customers within a specific section of the restaurant.
 */
class Section {
protected:
    std::string name; /**< The name of the section. */
    int capacity; /**< The maximum capacity of the section. */
    std::vector<std::shared_ptr<Table>> tables; /**< A vector of shared pointers to tables in this section. */

public:
    /**
     * @brief Constructor for the Section class.
     * @param name The name of the section.
     * @param capacity The maximum capacity of the section.
     */
    Section(std::string name, int capacity);

    /**
     * @brief Destructor for the Section class.
     */
    ~Section();

    /**
     * @brief Get a vector of shared pointers to tables in this section.
     * @return A vector of shared pointers to tables.
     */
    std::vector<std::shared_ptr<Table>> getTables();

    /**
     * @brief Set the vector of shared pointers to tables in this section.
     * @param tables A vector of shared pointers to tables.
     */
    void setTables(std::vector<std::shared_ptr<Table>> tables);

    /**
     * @brief Add a table to this section.
     * @param table A shared pointer to the table to be added.
     */
    void addTable(std::shared_ptr<Table> table);

    /**
     * @brief Remove a table from this section.
     * @param table A shared pointer to the table to be removed.
     */
    void removeTable(std::shared_ptr<Table> table);

    /**
     * @brief Get a vector of shared pointers to customers in this section.
     * @return A vector of shared pointers to customers in this section.
     */
    std::vector<std::shared_ptr<CustomerTemplate>> getAllCustomers();

    /**
     * @brief Merge two tables into one.
     * @param tableId1 The ID of the first table to be merged.
     * @param tableId2 The ID of the second table to be merged.
     * @return A shared pointer to the merged table.
     */
    std::shared_ptr<Table> mergeTables(int tableId1, int tableId2);

    /**
     * @brief Split a table into multiple tables.
     * @param table A shared pointer to the table to be split.
     * @return A vector of shared pointers to the newly created tables.
     */
    std::vector<std::shared_ptr<Table>> splitTable(std::shared_ptr<Table> table);
};

#endif
