#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>
#include <memory> 
#include <iostream>

class PrivateSection;
class GeneralSection;
class Host;

class ReservationSystem {
    private:
        std::shared_ptr<PrivateSection> privateSection;
        std::shared_ptr<GeneralSection> generalSection;

    public:
        ReservationSystem();
        ~ReservationSystem();
        std::shared_ptr<Section> getPrivateSection();
        std::shared_ptr<Section> getGeneralSection();
        std::vector<std::shared_ptr<Customer>> getCustomers();
        void clearOutTable(std::shared_ptr<Table> table);
        
};

#endif
