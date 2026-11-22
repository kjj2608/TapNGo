#include "Payment.h"
#include <new>

bool Payment::isValidCard(std::string card){
    size_t length = card.size();
    if(length > 3 && length < 25){
        for(int i = 0; i < length; i++){
            if(card[i] < '0' || card[i] > '9'){
                return false;
            }
        }
        return true;
    }
    return false;
}

void Payment::addTransaction(transaction **front, transaction **rear, int seatno, int f){
    transaction *temp = NULL;
    temp = new(std::nothrow) transaction;
    if(temp != NULL){
        count++;
        temp->fare = f;
        temp->seatnumber = seatno;
        temp->status = "SUCCESS";
        temp->next = NULL;
        if((*front) == NULL && (*rear) == NULL){
            (*front) = (*rear) = temp;
        } else {
            (*rear)->next = temp;
            (*rear) = temp;
        }
    }else {
        std::cout << "Memory Allocation Failed\n";
    }
}


void Payment::removeTransaction(transaction **front, transaction **rear, int seatno) {
    if(*front == NULL) {
        std::cout << "No transactions to remove.\n";
        return;
    }
    transaction *temp = *front;
    transaction *prev = NULL;
    while(temp != NULL && temp->seatnumber != seatno) {
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL) {
        *front = temp->next;
    } else {
        prev->next = temp->next;
    }
    if(temp == *rear) {
        *rear = prev;
    }

    delete temp;
    count--;
}


void Payment::displayTransaction(){
    std::cout << "Queued Transactions: " << count <<std::endl;
    transaction *temp = front;
    while(temp != NULL){
        std::cout << "Seat " << temp->seatnumber << " | Amount " << temp->fare << " | " << temp->status <<std::endl;
        temp = temp->next;
    }
}
