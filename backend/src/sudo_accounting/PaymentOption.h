#ifndef PAYMENTOTIONS_H
#define PAYMENTOTIONS_H
#include <iostream>
#include <string>
class Payment{
    private:
    std::string payment;
    double bill;
    public:
        void receivePaymentType(std::string payment){
            std::cout<<"Payment type received as "<<payment<<std::endl;
        };

        void receiveBill(double bill){
            std::cout<<"Bill received as R"<<bill<<std::endl;
        };
};
#endif