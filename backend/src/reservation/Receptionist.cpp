#include "Receptionist.h"

#include "Reservation.h"
#include "../customercare/Customer.h"
#include "Host.h"
#include "ReservationSystem.h"
#include "Section.h"
#include "Table.h"
#include "PrivateSection.h"
#include "GeneralSection.h"

Receptionist::Receptionist(std::shared_ptr<ReservationSystem> reservationSystem)  {
    this->reservationSystem = reservationSystem;
}

Receptionist::~Receptionist() {

}

void Receptionist::requestReservation(std::shared_ptr<CustomerTemplate> customer,std::string section) {
    std::shared_ptr<Section> reqestedSection;
    if(section=="Private Section"){
        reqestedSection = this->reservationSystem->getPrivateSection();
    }else{
        reqestedSection = this->reservationSystem->getGeneralSection();
    }
    if(reqestedSection==nullptr){
        return;
    }
    std::vector<std::shared_ptr<Table>> table = reqestedSection->getTables();
    std::shared_ptr<Table> availableTable;
    for(int i=0;i<(int)table.size();i++){
        if(table[i]->getIsReserved()==false){
            availableTable = table[i];
            break;
        }
    }
    if(availableTable==nullptr){
        return;
    }
    availableTable->setIsReserved(true);
    std::shared_ptr<Reservation> reservation = this->createReservation(customer,availableTable);
    customer->setReservation(reservation);
}

std::shared_ptr<Host> Receptionist::createHost(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<Customer> customer) {
    std::shared_ptr<Host> host = std::make_shared<Host>(section,reservation,customer);
    return host;
}

std::shared_ptr<Reservation> Receptionist::createReservation(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table) {
    std::shared_ptr<Reservation> reservation = std::make_shared<Reservation>(customer,table);
    return reservation;
}

