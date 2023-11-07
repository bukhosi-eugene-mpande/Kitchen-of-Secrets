#ifndef Section_H
#define Section_H

#include <string>
#include <vector>
#include <memory>

class Table;
class Customer;

/**
 * @brief The Section class represents a section in a restaurant.
 */
class Section{

    protected:
        std::string name; /**< The name of the section. */
        int capacity; /**< The maximum number of customers that can be seated in the section. */
        std::vector<std::shared_ptr<Table>> tables; /**< The tables in the section. */
        
    public:
        /**
         * @brief Constructs a new Section object.
         * 
         * @param name The name of the section.
         * @param capacity The maximum number of customers that can be seated in the section.
         */
        Section(std::string name,int capacity);

        /**
         * @brief Destroys the Section object.
         */
        ~Section();

        /**
         * @brief Returns the tables in the section.
         * 
         * @return std::vector<std::shared_ptr<Table>> The tables in the section.
         */
        std::vector<std::shared_ptr<Table>> getTables();
        
        /**
         * @brief Sets the tables in the section.
         * 
         * @param tables The tables to set.
         */
        void setTables(std::vector<std::shared_ptr<Table>> tables);

        /**
         * @brief Adds a table to the section.
         * 
         * @param table The table to add.
         */
        void addTable(std::shared_ptr<Table> table);

        /**
         * @brief Removes a table from the section.
         * 
         * @param Table The table to remove.
         */
        void removeTable(std::shared_ptr<Table> Table);
        
        /**
         * @brief Returns all the customers in the section.
         * 
         * @return std::vector<std::shared_ptr<CustomerTemplate>> All the customers in the section.
         */
        std::vector<std::shared_ptr<CustomerTemplate>> getAllCustomers();

        /**
         * @brief Merges two tables in the section.
         * 
         * @param tableId1 The ID of the first table to merge.
         * @param tableId2 The ID of the second table to merge.
         * @return std::shared_ptr<Table> The merged table.
         */
        std::shared_ptr<Table> mergeTables(int tableId1, int tableId2);

        /**
         * @brief Splits a table in the section.
         * 
         * @param table The table to split.
         * @return std::vector<std::shared_ptr<Table>> The split tables.
         */
        std::vector<std::shared_ptr<Table>> splitTable(std::shared_ptr<Table> table);

};

#endif