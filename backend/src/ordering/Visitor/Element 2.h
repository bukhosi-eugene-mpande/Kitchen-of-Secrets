#ifndef ELEMENT_H
#define ELEMENT_H

class Element{
public:
    virtual void accept(Visitor* visitor) = 0;
};
#endif