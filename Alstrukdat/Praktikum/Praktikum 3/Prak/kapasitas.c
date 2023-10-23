#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "listdin.h"

int main(){
    ListDin A;
    int cap, x, q, tipe;
    IdxType i;

    CreateListDin(&A, 0);
    scanf("%d", &q);

    for(i=0; i<q; i++){
        scanf("%d", &tipe);
        if(tipe == 1){
            scanf("%d", &x);
            if(CAPACITY(A) == 0){
                CAPACITY(A) = 1;
                insertLast(&A,x);
            }
            else if (isFull(A)){
                CAPACITY(A) *= 2;
                insertLast(&A,x);
            }
            else{
                insertLast(&A,x);
            }
        }

        else if(tipe == 2){
            deleteLast(&A, &x);
            if(NEFF(A) <= (CAPACITY(A)/2)){
                CAPACITY(A) = CAPACITY(A)/2;
            }
        }

        else if(tipe == 3){
            printf("%d ", CAPACITY(A));
            printList(A);
            printf("\n");
        }
    }
    return 0;
}