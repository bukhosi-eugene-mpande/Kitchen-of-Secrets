#ifndef BILLING_H
#define BILLING_H

#include "BillStrategy.h"
#include "backend/src/management/GameComponent.h"

class Billing : public GameComponent
{
private:
    /**
     * @brief `std::shared_ptr<BillStrategy> billStrategy;` is declaring a member variable 
     * `billStrategy` of type `std::shared_ptr<BillStrategy>`.
     * 
     */
    std::shared_ptr<BillStrategy> billStrategy;

    /**
     * @brief The line `double amount;` is declaring a member variable `amount` of type
     * `double`. This variable is used to store the amount of money for billing purposes.
     * 
     */
    double amount;

public:
    /**
     * @brief Construct a new Billing object
     * 
     * @param engine 
     * @param billStrategy 
     */
    Billing(std::shared_ptr<Engine> engine, std::shared_ptr<BillStrategy> billStrategy);

    /**
     * @brief Get the Amount object
     * 
     * @return double 
     */
    double getAmount();

    /**
     * @brief Set the Amount object
     * 
     * @param amount 
     */
    void setAmount(double amount);

    /**
     * @brief The line `json pay(double amount);` is declaring a member function named `pay`
     * that takes a `double` parameter `amount` and returns a `json` object. This function
     * is responsible for processing the payment with the specified amount and returning
     * the result as a `json` object.
     * 
     * @param amount 
     * @return json 
     */
    json pay(double amount);
    
    /**
     * @brief The set() participant in the Mediator Design Pattern. The function notifies all
     * gameComponents of "Transaction Complete" event.
     * 
     */
    virtual void sendEvent();

    /**
     * @brief The get() participant in the Mediator Design Pattern. The function recieves an
     * event message. If the event message reads "Pay Bill" then @ref pay(double) is called
     * so that the Customer(s) can pay their bill. Afterwards @ref sendEvent() is called. 
     * 
     * @param event 
     */
    virtual void receiveEvent(std::string event);
};

#endif