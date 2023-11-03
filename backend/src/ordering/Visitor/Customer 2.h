#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Element.h"
#include "Visitor.h"
#include "OrderBuilder.h"
#include <string>

class Customer : public Element {
private:
    std::string name;
    Order* order;
    std::string paymentOfChoice;
public:
    Customer(const std::string& name,const std::string& paymentOfChoice);
    void accept(Visitor* visitor) override;
    std::string getName() const;
    std::string getPaymentOfChoice() const;
    void eatFood(Order* order);

};

#endif // CUSTOMER_H
