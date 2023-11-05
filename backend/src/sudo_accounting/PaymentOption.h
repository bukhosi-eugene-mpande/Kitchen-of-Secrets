#ifndef PAYMENTOTIONS_H
#define PAYMENTOTIONS_H
#include <iostream>
#include <string>
class Accounting{
    private:
    std::string payment;
    double bill;
    public:
        void receivePaymentType(std::string payment){
            std::cout<<"Payment type received as "<<payment<<std::endl;
        };

        void pay(std::string paymentType, double bill)
        {
            std::cout<<"Payment type and bill received"<<std::endl;
        }
        void receiveBill(double bill){
            std::cout<<"Bill received as R"<<bill<<std::endl;
        };
};
#endif