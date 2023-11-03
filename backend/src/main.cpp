#include <iostream>

#include "../tests/includes/customercare_all.cpp"
#include "../tests/includes/reservation_all.cpp"
#include "../tests/includes/inventory_all.cpp"
#include "../tests/includes/ordering_all.cpp"
#include "../tests/includes/cooking_all.cpp"
#include "../tests/includes/management_all.cpp"

int main() {

    std::shared_ptr<Management> management = std::make_shared<Management>();
    Customer*  customer1 = new Customer(management);
    Customer*  customer2 = new Customer(management);
    CustomerNPC* customer3 = new CustomerNPC(management,true,"General Section");
    CustomerNPC* customer4 = new CustomerNPC(management,true,"Private Section");

    customer3->getDesiredSection();

    customer1->setManagement(management);
    customer1->setDesiredSection("General Section");
    customer1->requestReservation();

    customer2->setManagement(management);
    customer2->setDesiredSection("Private Section");
    customer2->requestReservation();

    customer3->setManagement(management);
    customer3->requestReservation();

    customer4->setManagement(management);
    customer4->requestReservation();


    customer1->requestToBeSeated();

    customer2->requestToBeSeated();

    customer3->requestToBeSeated();

    customer4->requestToBeSeated();

    std::shared_ptr<Section> privateSection = management->getPrivateSection();

    std::shared_ptr<Section> generalSection = management->getPrivateSection();

    std::shared_ptr<Table> table1 = customer1->getReservation()->getTable();

    std::shared_ptr<Table> table2 = customer2->getReservation()->getTable();

    std::shared_ptr<Table> table3 = customer3->getReservation()->getTable();

    std::shared_ptr<Table> table4 = customer4->getReservation()->getTable();

    std::vector<std::shared_ptr<CustomerTemplate>> customersPri = privateSection->getAllCustomers();
    std::vector<std::shared_ptr<CustomerTemplate>> customersGen = generalSection->getAllCustomers();

    bool flag = false;

    for(int i=0;i<(int)customersGen.size();i++){
        if(customersGen[i]->getName()=="Main Character"){
            flag = true;
        }
    }

    flag = false;

    for(int i=0;i<(int)customersPri.size();i++){
        if(customersPri[i]->getName()=="Main Character"){
            flag = true;
        }
    }


    flag = false;

    for(int i=0;i<(int)customersGen.size();i++){
        if(customersGen[i]->getName()=="NPC"){
            flag = true;
        }
    }


    flag = false;

    for(int i=0;i<(int)customersPri.size();i++){
        if(customersPri[i]->getName()=="NPC"){
            flag = true;
        }
    }

    customer1->leave();

    customer2->leave();

    customer3->leave();

    customer4->leave();
     
    return 0;
}
