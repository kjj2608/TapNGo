#include "Payment.h"

bool Payment:: isValidCard(long int card){
    if(card > 999 and card <1000000000000000000000000);
        return true;
}

void Payment::addTransaction(transaction **front, transaction **rear, int seatno, int f){
    transaction *temp = NULL;
    temp = (transaction*) malloc(sizeof(transaction));
    if(temp != NULL){
        count++;
        temp->fare = f;
        temp->seatnumber = seatno;
        temp->status = "SUCCESS";
        if((*front) == NULL && (*rear) == NULL){
            (*front) = (*rear) = temp;
        } else {
            (*rear)->next = temp;
            (*rear) = temp;
        }
        (*rear)->next = NULL;
    }
}

void Payment::displayTransaction(){
    std::cout << "Queued Transactions: " << count <<std::endl;
    transaction *temp = NULL;
    temp = (transaction*) malloc(sizeof(transaction));
    temp = front;
    while(temp != NULL){
        std::cout << "Seat " << temp->seatnumber << " | Amount " << temp->fare << " | " << temp->status <<std::endl;
        temp = temp->next;
    }
}
