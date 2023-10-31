#ifndef ELEMENT_H
#define ELEMENT_H
#include "Visitor.h"
class Element{
public:
    virtual void accept(Visitor* visitor) = 0;
};
#endif