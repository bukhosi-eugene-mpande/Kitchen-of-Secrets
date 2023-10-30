#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "GameComponent.h"
#include "SatisfactionState.h"

class Customer : GameComponent {
    private:
        SatisfactionState* mood;
        std::string complaint;
        bool checkIn;
        bool checkOut;
        
    public:
        Customer(Engine* engine);
        ~Customer();
        SatisfactionState* getMood();
        void setMood(SatisfactionState* mood);
        std::string getComplaint();
        void setComplaint(std::string complaint);
        bool getCheckIn();
        void setCheckIn(bool checkIn);
        bool getCheckOut();
        void setCheckOut(bool checkOut);
        void helpMe();
        void directMe();
        virtual void sendNotification();
        virtual void receiveNotification(std::string message);
};

#endif