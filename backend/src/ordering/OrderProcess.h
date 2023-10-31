//this is the concreteVisitor.. 
//illustrating the entire order process
#ifndef ORDERPROCESS_H
#define ORDERPROCESS_H

#include "Visitor.h"
#include "Waiter.h"
#include "Customer.h"
#include "Management.h"
#include <string>
//concreteVisitor
class OrderProcess : public Visitor {
private:
    std::string paymentType;
    Management* management;
public:
    void visit(Waiter* waiter) override;
    void visit(Customer* customer) override;
    //void visit(Management* management) override;
};

#endif // ORDERPROCESS_H
