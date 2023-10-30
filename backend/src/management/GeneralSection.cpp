#include "GeneralSection.h"

GeneralSection::GeneralSection() {
    numberOfSeats = 4;
}

GeneralSection::~GeneralSection() {}

void GeneralSection::seatCustomers(std::vector<Customer*> customers) {
    if (customers.size() > numberOfSeats) {
        
    } else {
        std::vector<Customer*>::iterator availableCustomers = customers.begin();
        std::vector<Customer*>::iterator seatingIndex = availableSeats.begin();
        for (seatingIndex; seatingIndex < availableSeats.end(); seatingIndex++) {
            *seatingIndex = *availableCustomers;
            availableCustomers++;
        }
    }
}

void GeneralSection::combineTables()
{

}
