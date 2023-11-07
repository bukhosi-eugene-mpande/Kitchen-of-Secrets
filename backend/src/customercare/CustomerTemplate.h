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
 * @brief The CustomerTemplate class represents a customer in the restaurant.
 * 
 * This class contains information about the customer's reservation, system interaction, mood, guests, finished order, 
 * food and beverage orders, desired section, name, payment type, number of guests, total bill, and eating status.
 */
class CustomerTemplate{
    protected:
        std::shared_ptr<Reservation> reservation; /**< The customer's reservation. */
        std::shared_ptr<PlayerInteraction> management; /**< The system interaction for the customer. */
        std::shared_ptr<SatisfactionState> Mood; /**< The mood of the customer. */
        std::vector<std::shared_ptr<CustomerTemplate>> guests; /**< The guests of the customer. */
        std::shared_ptr<Order> finishedOrder; /**< The finished order of the customer. */
        std::unordered_map<std::string,int> FoodOrder; /**< The food order of the customer. */
        std::unordered_map<std::string,int> BevarageOrder; /**< The beverage order of the customer. */
        std::unordered_map<std::string,int> order; /**< The order of the customer. */
        std::string DesiredSection; /**< The desired section of the customer. */
        std::string name; /**< The name of the customer. */
        std::string paymentType; /**< The payment type of the customer. */
        int numberOfGuests; /**< The number of guests of the customer. */
        double totalBill; /**< The total bill of the customer. */
        bool isDoneEating; /**< The eating status of the customer. */
        bool readyToOrder; /**< The readiness of the customer to order. */
        bool readyToPay; /**< The readiness of the customer to pay. */
        bool ordered; /**< The order status of the customer. */
        bool hasGuests; /**< The presence of guests of the customer. */
        bool isMain; /**< The main status of the customer. */
        bool isEating; /**< The eating status of the customer. */

    public:
        /**
         * @brief Constructs a new CustomerTemplate object.
         * 
         * @param name The name of the customer.
         * @param management The system interaction for the customer.
         */
        CustomerTemplate(std::string name, std::shared_ptr<PlayerInteraction> management);

        /**
         * @brief Destroys the CustomerTemplate object.
         * 
         */
        ~CustomerTemplate();

        /**
         * @brief Gets the mood of the customer.
         * 
         * @return std::shared_ptr<SatisfactionState> The mood of the customer.
         */
        std::shared_ptr<SatisfactionState> getMood();

        /**
         * @brief Calculates the final bill of the customer.
         * 
         * @param bill The bill of the customer.
         * @return double The final bill of the customer.
         */
        double calculateFinalBill(double bill);

        /**
         * @brief Gets the eating status of the customer.
         * 
         * @return bool The eating status of the customer.
         */
        bool getIsEating();

        /**
         * @brief Sets the eating status of the customer.
         * 
         */
        void setIsEating();

        /**
         * @brief Sets the mood of the customer.
         * 
         * @param Mood The mood of the customer.
         */
        void setMood(std::shared_ptr<SatisfactionState> Mood);

        /**
         * @brief Gets the order of the customer.
         * 
         * @return std::unordered_map<std::string,int> The order of the customer.
         */
        std::unordered_map<std::string,int> getOrder();

        /**
         * @brief Gets the name of the customer.
         * 
         * @return std::string The name of the customer.
         */
        std::string getName();

        /**
         * @brief Gets the payment type of the customer.
         * 
         * @return std::string The payment type of the customer.
         */
        std::string getPaymentType();

        /**
         * @brief Sets the payment type of the customer.
         * 
         * @param getPaymentType The payment type of the customer.
         * @return std::string The payment type of the customer.
         */
        std::string setpaymentType(std::string getPaymentType);

        /**
         * @brief Checks if the customer is ready to order.
         * 
         * @return bool The readiness of the customer to order.
         */
        bool IsReadyToOrder();

        /**
         * @brief Checks if the customer is ready to pay.
         * 
         * @return bool The readiness of the customer to pay.
         */
        bool IsReadyToPay();

        /**
         * @brief Requests the beverage order of the customer.
         * 
         * @param menu The menu of the restaurant.
         * @return std::unordered_map<std::string,int> The beverage order of the customer.
         */
        std::unordered_map<std::string,int> requestBeverageOrder(std::shared_ptr<Menu> menu);

        /**
         * @brief Requests the food order of the customer.
         * 
         * @param menu The menu of the restaurant.
         * @return std::unordered_map<std::string,int> The food order of the customer.
         */
        std::unordered_map<std::string,int> requestFoodOrder(std::shared_ptr<Menu> menu);

        /**
         * @brief Generates the beverage order of the customer.
         * 
         * @param menu The menu of the restaurant.
         * @return std::unordered_map<std::string,int> The beverage order of the customer.
         */
        std::unordered_map<std::string,int> generateBeverageOrder(std::shared_ptr<Menu> menu);

        /**
         * @brief Generates the food order of the customer.
         * 
         * @param menu The menu of the restaurant.
         * @return std::unordered_map<std::string,int> The food order of the customer.
         */
        std::unordered_map<std::string,int> generateFoodOrder(std::shared_ptr<Menu> menu);

        /**
         * @brief Sets the order of the customer.
         * 
         * @param order The order of the customer.
         */
        void setOrder(std::unordered_map<std::string,int> order);

        /**
         * @brief Sets the beverage order of the customer.
         * 
         * @param order The beverage order of the customer.
         */
        void setBeverageOrder(std::unordered_map<std::string,int> order);

        /**
         * @brief Sets the food order of the customer.
         * 
         * @param order The food order of the customer.
         */
        void setFoodOrder(std::unordered_map<std::string,int> order);

        /**
         * @brief Gets the beverage order of the customer.
         * 
         * @return std::unordered_map<std::string,int> The beverage order of the customer.
         */
        std::unordered_map<std::string,int> getBeverageOrder();

        /**
         * @brief Gets the food order of the customer.
         * 
         * @return std::unordered_map<std::string,int> The food order of the customer.
         */
        std::unordered_map<std::string,int> getFoodOrder();

        /**
         * @brief Gets the order status of the customer.
         * 
         * @return bool The order status of the customer.
         */
        bool getOrdered();

        /**
         * @brief Sets the order status of the customer.
         * 
         * @param ordered The order status of the customer.
         */
        void setOrdered(bool ordered);

        /**
         * @brief Gets the finished order of the customer.
         * 
         * @return std::shared_ptr<Order> The finished order of the customer.
         */
        std::shared_ptr<Order> getFinishedOrder();

        /**
         * @brief Sets the finished order of the customer.
         * 
         * @param order The finished order of the customer.
         */
        void setFinishedOrder(std::shared_ptr<Order> order);

        /**
         * @brief Sets the total bill of the customer.
         * 
         * @param bill The total bill of the customer.
         */
        void setTotalBill(double bill);

        /**
         * @brief Gets the total bill of the customer.
         * 
         * @return double The total bill of the customer.
         */
        double getTotalBill();

        /**
         * @brief Sets the readiness of the customer to order.
         * 
         * @param readyToOrder The readiness of the customer to order.
         */
        void setReadyToOrder(bool readyToOrder);

        /**
         * @brief Sets the readiness of the customer to pay.
         * 
         * @param readyToPay The readiness of the customer to pay.
         */
        void setReadyToPay(bool readyToPay);

        /**
         * @brief Prints the customer's information to the console.
         * 
         */
        void console();

        /**
         * @brief Makes the customer angry.
         * 
         */
        void anger();

        /**
         * @brief Notifies the system interaction of the customer.
         * 
         */
        void notifyPlayerInteraction();

        /**
         * @brief Makes the customer leave the restaurant.
         * 
         */
        void leave();

        /**
         * @brief Gets the reservation of the customer.
         * 
         * @return std::shared_ptr<Reservation> The reservation of the customer.
         */
        std::shared_ptr<Reservation> getReservation();

        /**
         * @brief Sets the reservation of the customer.
         * 
         * @param reservation The reservation of the customer.
         */
        void setReservation(std::shared_ptr<Reservation> reservation);

        /**
         * @brief Gets the system interaction of the customer.
         * 
         * @return std::shared_ptr<PlayerInteraction> The system interaction of the customer.
         */
        std::shared_ptr<PlayerInteraction> getPlayerInteraction();

        /**
         * @brief Sets the system interaction of the customer.
         * 
         * @param PlayerInteraction The system interaction of the customer.
         */
        void setPlayerInteraction(std::shared_ptr<PlayerInteraction> PlayerInteraction);

        /**
         * @brief Converts the customer to a shared pointer.
         * 
         * @return std::shared_ptr<CustomerTemplate> The customer as a shared pointer.
         */
        std::shared_ptr<CustomerTemplate> this_to_shared();
        
        /**
         * @brief Gets the presence of guests of the customer.
         * 
         * @return bool The presence of guests of the customer.
         */
        bool getHasGuests();

        /**
         * @brief Sets the presence of guests of the customer.
         * 
         * @param hasGuests The presence of guests of the customer.
         */
        void setHasGuests(bool hasGuests);

        /**
         * @brief Gets the main status of the customer.
         * 
         * @return bool The main status of the customer.
         */
        bool getIsMain();

        /**
         * @brief Sets the main status of the customer.
         * 
         * @param isMain The main status of the customer.
         */
        void setIsMain(bool isMain);

        /**
         * @brief Gets the number of guests of the customer.
         * 
         * @return int The number of guests of the customer.
         */
        int getNumGuests();

        /**
         * @brief Sets the number of guests of the customer.
         * 
         * @param numGuests The number of guests of the customer.
         */
        void setNumGuests(int numGuests);

        /**
         * @brief Requests a reservation for the customer.
         * 
         */
        void requestReservation();

        /**
         * @brief Adds a guest to the customer's party.
         * 
         * @param guest The guest to be added.
         */
        void addGuest(std::shared_ptr<CustomerTemplate> guest);

        /**
         * @brief Gets the guests of the customer.
         * 
         * @return std::vector<std::shared_ptr<CustomerTemplate>> The guests of the customer.
         */
        std::vector<std::shared_ptr<CustomerTemplate>> getGuests();

        /**
         * @brief Gets the desired section of the customer.
         * 
         * @return std::string The desired section of the customer.
         */
        std::string getDesiredSection();

        /**
         * @brief Sets the desired section of the customer.
         * 
         * @param section The desired section of the customer.
         */
        void setDesiredSection(std::string section);

        /**
         * @brief Requests to be seated in the restaurant.
         * 
         */
        void requestToBeSeated();

        /**
         * @brief Generates a random number within a range.
         * 
         * @param min The minimum value of the range.
         * @param max The maximum value of the range.
         * @return int The generated random number.
         */
        int generateRandomNum(int min, int max);

        /**
         * @brief Sets the payment type of the customer.
         * 
         * @param paymentType The payment type of the customer.
         */
        void setPaymentType(std::string paymentType);

        /**
         * @brief Sets the eating status of the customer.
         * 
         * @param isDoneEating The eating status of the customer.
         */
        void setDoneEating(bool isDoneEating);

        /**
         * @brief Gets the eating status of the customer.
         * 
         * @return bool The eating status of the customer.
         */
        bool getDoneEating();

        /**
         * @brief Sets the system interaction for the customer.
         * 
         * @param management The system interaction for the customer.
         */
        void setManagement(std::shared_ptr<PlayerInteraction> management);

};
#endif