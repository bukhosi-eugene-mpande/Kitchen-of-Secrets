#include "CustomerCareSystem.h"
void CustomerCareSystem::attach(std::shared_ptr<CustomerObserver> customerObserver) {
    customerObserverList.push_back(customerObserver);
}
void CustomerCareSystem::detach(std::shared_ptr<CustomerObserver> customerObserver){
    auto it = std::find(customerObserverList.begin(), customerObserverList.end(), customerObserver);
    if (it != customerObserverList.end()) {
        customerObserverList.erase(it);
    }
}
void CustomerCareSystem::notify(){
     for (std::shared_ptr<CustomerObserver> customerObserver : customerObserverList) {
            customerObserver->updateCustomerMood();
        }
}