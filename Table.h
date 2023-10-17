#ifndef TABLE_H
#define TABLE_H

/**
 * @file BridgePattern.cpp
 * @brief Implementation of the Bridge Design Pattern for restaurant seating management.
 */

#include <iostream>

// Implementor interface
class TableImplementation {
public:
    /**
     * @brief Check if the table is available.
     * @return true if the table is available, false otherwise.
     */
    virtual bool isAvailable() = 0;

    /**
     * @brief Assign the table to a customer.
     */
    virtual void assignTable() = 0;

    /**
     * @brief Mark the table as occupied.
     */
    virtual void markOccupied() = 0;
};

// Concrete Implementors
class SmokingTable : public TableImplementation {
public:
    bool isAvailable() override {
        // Check availability logic for smoking table
        return true; // Replace with actual logic
    }

    void assignTable() override {
        // Assign a smoking table to a customer
        // Update the table status
    }

    void markOccupied() override {
        // Mark the smoking table as occupied
    }
};

class PrivateTable : public TableImplementation {
public:
    bool isAvailable() override {
        // Check availability logic for private table
        return true; // Replace with actual logic
    }

    void assignTable() override {
        // Assign a private table to a customer
        // Update the table status
    }

    void markOccupied() override {
        // Mark the private table as occupied
    }
};

class GeneralTable : public TableImplementation {
public:
    bool isAvailable() override {
        // Check availability logic for general table
        return true; // Replace with actual logic
    }

    void assignTable() override {
        // Assign a general table to a customer
        // Update the table status
    }

    void markOccupied() override {
        // Mark the general table as occupied
    }
};

// Abstraction (SeatingPlan)
class SeatingPlan {
protected:
    TableImplementation* table;

public:
    SeatingPlan(TableImplementation* tableImpl) : table(tableImpl) {
    }

    /**
     * @brief Assign the table to a customer.
     */
    virtual void assignTable() {
        if (table->isAvailable()) {
            table->assignTable();
        } else {
            std::cout << "Table is not available." << std::endl;
        }
    }

    /**
     * @brief Mark the table as occupied.
     */
    virtual void markTableOccupied() {
        table->markOccupied();
    }

    /**
     * @brief Check if the table is available.
     * @return true if the table is available, false otherwise.
     */
    virtual bool isTableAvailable() {
        return table->isAvailable();
    }
};

// Refined Abstraction (Section-specific seating plans)
class SmokingSection : public SeatingPlan {
public:
    SmokingSection(TableImplementation* tableImpl) : SeatingPlan(tableImpl) {
    }
};

class PrivateSection : public SeatingPlan {
public:
    PrivateSection(TableImplementation* tableImpl) : SeatingPlan(tableImpl) {
    }
};

class GeneralSection : public SeatingPlan {
public:
    GeneralSection(TableImplementation* tableImpl) : SeatingPlan(tableImpl) {
    }
};

#endif