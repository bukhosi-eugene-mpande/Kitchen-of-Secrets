#ifndef CUSTOMERCARESYSTEM_H
#define CUSTOMERCARESYSTEM_H
#include "CustomerObserver.h"
#include <string>
#include <vector>
#include <algorithm>
class CustomerObserver;
using namespace std;
class CustomerCareSystem
{
private:
    std::vector<CustomerObserver*> CustomerObserverList;

public:
    void attach(CustomerObserver *CustomerObserver);
    void detach(CustomerObserver *CustomerObserver);
    void notify();
};
#endif