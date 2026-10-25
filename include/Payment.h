#ifndef PAYMENT_H
#define PAYMENT_H

#include "Passenger.h"
#include <string>
#include <stdlib.h>
#include <iostream>

class Payment {
    private:
        typedef struct node{
            int seatnumber, fare;
            std::string status;
            struct node *next;
        }transaction;
        transaction *front = NULL, *rear = NULL;
        int count = 0;
    public:
        bool isValidCard(long int cardno);
        void addTransaction(int seatno, int f){
            addTransaction(&front, &rear, seatno, f);
        }
        void addTransaction(transaction **front, transaction **rear, int seatno, int f);
        void displayTransaction();
};

#endif