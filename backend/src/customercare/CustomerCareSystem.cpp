#include "CustomerCareSystem.h"
void CustomerCareSystem::attach(CustomerObserver *CustomerObserver){
    CustomerObserverList.push_back(CustomerObserver);
}
void CustomerCareSystem::detach(CustomerObserver *CustomerObserver){
    auto it = std::find(CustomerObserverList.begin(), CustomerObserverList.end(), CustomerObserver);
    if (it != CustomerObserverList.end()) {
        CustomerObserverList.erase(it);
    }
}
void CustomerCareSystem::notify(){
     for (CustomerObserver* CustomerObserver : CustomerObserverList) {
            CustomerObserver->updateCustomerMood();
        }

}