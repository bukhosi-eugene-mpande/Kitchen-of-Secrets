#ifndef PAYMENTOTIONS_H
#define PAYMENTOTIONS_H
#include <iostream>
#include <string>
class Accounting{
    private:
    std::string payment;
    double bill;
    public:
        std::string receivePaymentType(std::string payment){
            return "Payment type received as "+payment;
        };

        std::string pay(std::string paymentType, double bill)
        {
            return "Payment type and bill received";
        }
        std::string receiveBill(double bill){
            return "Bill received";
        };
};
#endif