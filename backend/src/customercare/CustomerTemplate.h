/**
 * @file CustomerTemplate.h
 * @brief Contains the declaration of the CustomerTemplate class.
 */

#ifndef CUSTOMER_TEMPLATE_H
#define CUSTOMER_TEMPLATE_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "../management/PlayerInteraction.h"
#include "../reservation/Reservation.h"
class SatisfactionState;
class Waiter;
class Menu;
class Order;

/**
 * @class CustomerTemplate
 * @brief Represents a template for customer behavior in the restaurant.
 *
 * The CustomerTemplate class provides a template for modeling customer behavior in the restaurant. It includes attributes and methods related to reservations, orders, mood, and interactions with the restaurant management system.
 */
class CustomerTemplate{
protected:
    //reservation
    std::shared_ptr<Reservation> reservation;
    //system interaction
    std::shared_ptr<PlayerInteraction> management;
    //mood a customer is in
    std::shared_ptr<SatisfactionState> Mood;
    //guests
    std::vector<std::shared_ptr<CustomerTemplate>> guests;
    //finished order
    std::shared_ptr<Order> finishedOrder;

    std::unordered_map<std::string,int> FoodOrder;
    std::unordered_map<std::string,int> BevarageOrder;
    std::unordered_map<std::string,int> order;

    std::string DesiredSection;
    std::string name;
    std::string paymentType;

    int numberOfGuests;

    double totalBill;

    bool isDoneEating;
    bool readyToOrder;
    bool readyToPay;
    bool ordered;
    bool hasGuests;
    bool isMain;
    bool isEating;

public:
    /**
     * @brief Constructor for the CustomerTemplate class.
     * @param name The name of the customer.
     * @param management A shared pointer to the player interaction management.
     */
    CustomerTemplate(std::string name, std::shared_ptr<PlayerInteraction> management);

    /**
     * @brief Destructor for the CustomerTemplate class.
     */
    ~CustomerTemplate();

    /**
     * @brief Get the mood of the customer.
     * @return A shared pointer to the customer's mood state.
     */
    std::shared_ptr<SatisfactionState> getMood();

    /**
     * @brief Calculate the final bill based on the customer's satisfaction level.
     * @param bill The initial bill amount.
     * @return The final bill amount.
     */
    double calculateFinalBill(double bill);

    /**
     * @brief Check if the customer is currently eating.
     * @return True if the customer is eating, otherwise false.
     */
    bool getIsEating();

        void setIsEating();

        void setMood(std::shared_ptr<SatisfactionState> Mood);

        std::unordered_map<std::string,int> getOrder();

        std::string getName();

        std::string getPaymentType();

        std::string setpaymentType(std::string getPaymentType);

        bool IsReadyToOrder();

        bool IsReadyToPay();

        std::unordered_map<std::string,int> requestBeverageOrder(std::shared_ptr<Menu> menu);

        std::unordered_map<std::string,int> requestFoodOrder(std::shared_ptr<Menu> menu);

        std::unordered_map<std::string,int> generateBeverageOrder(std::shared_ptr<Menu> menu);

        std::unordered_map<std::string,int> generateFoodOrder(std::shared_ptr<Menu> menu);

        void setOrder(std::unordered_map<std::string,int> order);

        void setBeverageOrder(std::unordered_map<std::string,int> order);

        void setFoodOrder(std::unordered_map<std::string,int> order);

        std::unordered_map<std::string,int> getBeverageOrder();

        std::unordered_map<std::string,int> getFoodOrder();

        bool getOrdered();

        void setOrdered(bool ordered);

        std::shared_ptr<Order> getFinishedOrder();

        void setFinishedOrder(std::shared_ptr<Order> order);

        void setTotalBill(double bill);

        double getTotalBill();

        void setReadyToOrder(bool readyToOrder);

        void setReadyToPay(bool readyToPay);

        void console();

        void anger();

        void notifyPlayerInteraction();

        void leave();

        std::shared_ptr<Reservation> getReservation();

        void setReservation(std::shared_ptr<Reservation> reservation);

        std::shared_ptr<PlayerInteraction> getPlayerInteraction();

        void setPlayerInteraction(std::shared_ptr<PlayerInteraction> PlayerInteraction);

        std::shared_ptr<CustomerTemplate> this_to_shared();
        
        bool getHasGuests();

        void setHasGuests(bool hasGuests);

        bool getIsMain();

        void setIsMain(bool isMain);

        int getNumGuests();

        void setNumGuests(int numGuests);

        void requestReservation();

        void addGuest(std::shared_ptr<CustomerTemplate> guest);

        std::vector<std::shared_ptr<CustomerTemplate>> getGuests();

        std::string getDesiredSection();

        void setDesiredSection(std::string section);

        void requestToBeSeated();

        int generateRandomNum(int min, int max);

        void setPaymentType(std::string paymentType);

        void setDoneEating(bool isDoneEating);

        bool getDoneEating();

        void setManagement(std::shared_ptr<PlayerInteraction> management);

};
#endif