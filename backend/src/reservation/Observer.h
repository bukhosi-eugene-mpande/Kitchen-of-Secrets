#ifndef OBS_H
#define OBS_H

/**
 * @file ObserverPattern.cpp
 * @brief Implementation of the Observer Design Pattern for restaurant seating plan notifications.
 */

#include <iostream>
#include <vector>

class Observer;

// Subject (SeatingPlan)
class SeatingPlanSubject {
protected:
    std::vector<Observer*> observers;

public:
    /**
     * @brief Register an observer to receive notifications.
     * @param observer The observer to register.
     */
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    /**
     * @brief Remove an observer from the list of recipients.
     * @param observer The observer to remove.
     */
    void removeObserver(Observer* observer) {
        // Remove the observer
    }

    /**
     * @brief Notify all registered observers of changes in the seating plan.
     */
    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

// Concrete Subjects (Section-specific seating plans)
class SmokingSectionSubject : public SeatingPlanSubject {
    // Include logic for managing the smoking section, tables, and notifications
};

class PrivateSectionSubject : public SeatingPlanSubject {
    // Include logic for managing the private section, tables, and notifications
};

class GeneralSectionSubject : public SeatingPlanSubject {
    // Include logic for managing the general section, tables, and notifications
};

// Observer interface
class Observer {
public:
    /**
     * @brief Update method called when the seating plan changes.
     */
    virtual void update() = 0;
};

// Concrete Observers
class Waiter : public Observer {
    void update() override {
        // Implement waiter's response to seating plan changes
        std::cout << "Waiter: Table assigned. Prepare for customers." << std::endl;
    }
};

class Manager : public Observer {
    void update() override {
        // Implement manager's response to seating plan changes
        std::cout << "Manager: Monitor the seating plan changes." << std::endl;
    }
};

class Customer : public Observer {
    void update() override {
        // Implement customer's response to seating plan changes
        std::cout << "Customer: Seated at the assigned table." << std::endl;
    }
};

#endif