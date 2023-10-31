#include "Customer.h"
#include "HeadChef.h" 
#include "Waiter.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
     Customer *tester = new Customer();
     Customer *table2 = new Customer();
     Customer *table3 = new Customer();
     Customer *table4 = new Customer();
     Customer *table5 = new Customer();
     Customer *table6 = new Customer();

     HeadChef *chef = new HeadChef();
     Waiter *waiter = new Waiter();

    
    tester->attach(chef);
    table2->attach(chef);
    table3->attach(chef);
    table4->attach(chef);
    table5->attach(chef);
    table6->attach(chef);

    tester->attach(waiter);
    table2->attach(waiter);
    table3->attach(waiter);
    table4->attach(waiter);
    table5->attach(waiter);
    table6->attach(waiter);


    table2->timeLaps();
    cout<<"\n"<<tester->toString();

    
    tester->timeLaps();
    cout<<"\n"<<tester->toString();
    tester->timeLaps();
    tester->helpMe();
    cout<<"\n"<<tester->toString();
    tester->timeLaps();
    cout<<"\n"<<tester->toString();


    // When a customer is in the "VeryUnhappy" state, the chef should intervene
    if (tester->getMood()->getStateName() == "Customer left")
    {
        std::vector<Customer *> tables = {table2, table3, table4, table5, table6};
        for (Customer *table : tables)
        {
            if (table->getMood()->getStateName() != "Customer left")
            {
                cout<<""<<endl;
                cout<<"chef iterator"<<endl;
                table->helpMe(); 
                cout<<table->toString();
            }
        }
    }

    // Simulate further state changes if necessary

    delete tester;
    delete table2;
    delete table3;
    delete table4;
    delete table5;
    delete table6;
    delete chef;
    delete waiter;

    return 0;
}