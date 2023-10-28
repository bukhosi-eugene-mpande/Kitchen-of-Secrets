#ifndef Reservation_H
#define Reservation_H

#include <iostream>

class Reservation {
    private:
        int tableId;
        int customerId;

    public:
        Reservation();
        ~Reservation();
        int getTableId();
        void setTableId(int tableId);
        int getCustomerId();
        void setCustomerId(int customerId);
};

#endif