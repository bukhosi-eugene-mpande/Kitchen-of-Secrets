#include "Receptionist.h"
#include "Reservation.h"
#include "Host.h"
#include "ReservationSystem.h"
#include "Section.h"
#include "Table.h"
#include "PrivateSection.h"
#include "GeneralSection.h"

Receptionist::Receptionist( std::shared_ptr<ReservationSystem> reservationSystem)  {
    this->reservationSystem = reservationSystem;
}

Receptionist::~Receptionist() {}

void Receptionist::requestReservation(std::shared_ptr<CustomerTemplate> customer, std::string section) {
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
            availableTable->setIsReserved(true);
            break;
        }
    }

    if(availableTable==nullptr){
        return;
    }

    if(customer->getNumGuests()>availableTable->getTableSize()){
        std::shared_ptr<Table> availableTable2;
        for(int i=0;i<(int)table.size();i++){
            if(table[i]->getIsReserved()==false){
                availableTable2 = table[i];
                availableTable2->setIsReserved(true);
                break;
            }
        }

        if(availableTable2==nullptr){
            return;
        }

        availableTable->setMarkedForMerge(true);
        availableTable2->setMarkedForMerge(true);

        std::shared_ptr<Table> table = reqestedSection->mergeTables(availableTable->getTableId(),availableTable2->getTableId());
        table->setIsReserved(true);
        table->setMarkedForMerge(true);
        std::shared_ptr<Reservation> reservation = this->createReservation(customer,table);
        
        if(reservation==nullptr){
            return;
        }

        customer->setReservation(reservation);   
        return;
    }
    std::shared_ptr<Reservation> reservation = this->createReservation(customer,availableTable);
    customer->setReservation(reservation);
}

std::shared_ptr<Host> Receptionist::createHost(std::shared_ptr<Section> section, std::shared_ptr<Reservation> reservation, std::shared_ptr<CustomerTemplate> customer) {
    std::shared_ptr<Host> host = std::make_shared<Host>(section,reservation,customer);
    return host;
}

std::shared_ptr<Reservation> Receptionist::createReservation(std::shared_ptr<CustomerTemplate> customer, std::shared_ptr<Table> table) {
    std::shared_ptr<Reservation> reservation = std::make_shared<Reservation>(customer,table);
    return reservation;
}

void Receptionist::requestToBeSeated(std::shared_ptr<CustomerTemplate> customer) {
    std::shared_ptr<Reservation> reservation = customer->getReservation();
    if(reservation==nullptr){
        return;
    }else{
        std::shared_ptr<Section> section;
        if(customer->getDesiredSection()=="Private Section"){
            section = this->reservationSystem->getPrivateSection();
        }else{
            section = this->reservationSystem->getGeneralSection();
        }
        std::shared_ptr<Host> host = this->createHost(section,reservation,customer);
        host->seatCustomer();
    }
}
