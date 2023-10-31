#ifndef VISITOR_H
#define VISITOR_H

// Forward declaration of classes
class Waiter;
class Customer;
class Management;

class Visitor
{
    public:
    virtual void visit(Waiter* waiter) = 0;
    virtual void visit(Customer* customer) = 0;
    //virtual void visit(Management* management) = 0;
};
#endif