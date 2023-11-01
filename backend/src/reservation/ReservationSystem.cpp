#include "ReservationSystem.h"

ReservationSystem::ReservationSystem() {
    this->privateSection = std::make_shared<PrivateSection>("Private", 10);
    this->generalSection = std::make_shared<GeneralSection>("General", 10);
}

ReservationSystem::~ReservationSystem() {

}

std::shared_ptr<PrivateSection> ReservationSystem::getPrivateSection() {
    return this->privateSection;
}

std::shared_ptr<GeneralSection> ReservationSystem::getGeneralSection() {
    return this->generalSection;
}

std::vector<std::shared_ptr<Customer>> ReservationSystem::getCustomers() {
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::shared_ptr<Customer>> privateSectionCustomers = this->privateSection->getAllCustomers();
    for (int i = 0; i < privateSectionCustomers.size(); i++) {
        customers.push_back(privateSectionCustomers[i]);
    }
    std::vector<std::shared_ptr<Customer>> generalSectionCustomers = this->generalSection->getAllCustomers();
    for (int i = 0; i < generalSectionCustomers.size(); i++) {
        customers.push_back(generalSectionCustomers[i]);
    }
    return customers;
}


