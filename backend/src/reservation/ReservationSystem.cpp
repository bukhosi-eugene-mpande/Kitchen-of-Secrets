#include "ReservationSystem.h"
#include "PrivateSection.h"
#include "GeneralSection.h"
#include "Host.h"

ReservationSystem::ReservationSystem() {
    this->privateSection = std::make_shared<PrivateSection>();
    this->generalSection = std::make_shared<GeneralSection>();
}

ReservationSystem::~ReservationSystem() {

}

std::shared_ptr<Section> ReservationSystem::getPrivateSection() {
    return this->privateSection;
}

std::shared_ptr<Section> ReservationSystem::getGeneralSection() {
    return this->generalSection;
}

std::vector<std::shared_ptr<CustomerTemplate>> ReservationSystem::getCustomers() {
    std::vector<std::shared_ptr<CustomerTemplate>> customers;
    std::vector<std::shared_ptr<CustomerTemplate>> privateSectionCustomers = this->privateSection->getAllCustomers();
    for (int i = 0; i < (int) privateSectionCustomers.size(); i++) {
        customers.push_back(privateSectionCustomers[i]);
    }
    std::vector<std::shared_ptr<CustomerTemplate>> generalSectionCustomers = this->generalSection->getAllCustomers();
    for (int i = 0; i < (int) generalSectionCustomers.size(); i++) {
        customers.push_back(generalSectionCustomers[i]);
    }
    return customers;
}

void ReservationSystem::clearOutTable(std::shared_ptr<Table> table) {
    table->clear();
}

