#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>
#include <memory> 
#include <iostream>

class PrivateSection;
class GeneralSection;
class Host;
class CustomerTemplate;

class ReservationSystem {
    private:
        std::shared_ptr<PrivateSection> privateSection;
        std::shared_ptr<GeneralSection> generalSection;
        std::vector<std::shared_ptr<CustomerTemplate>> garbage;
    public:
        ReservationSystem();
        ~ReservationSystem();
        std::shared_ptr<Section> getPrivateSection();
        std::shared_ptr<Section> getGeneralSection();
        std::vector<std::shared_ptr<CustomerTemplate>>  getCustomers();
        void clearOutTable(std::shared_ptr<Table> table);
};

#endif
