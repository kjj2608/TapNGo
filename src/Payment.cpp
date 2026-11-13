#include "Payment.h"

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

void Payment::removeTransaction(transaction **front, transaction **rear, int seatno){
    if((*front)->seatnumber == seatno){
        (*front) = (*front)->next;
    } else {
        transaction *temp = NULL, *del = NULL;
        temp = (transaction*) malloc(sizeof(transaction));
        del = (transaction*) malloc(sizeof(transaction));
        if(temp != NULL) {
            temp = (*front);
            while(temp->next->seatnumber != seatno){
                temp = temp->next;
            }
            del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
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
