#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

int main(){
    ListDin A;
    IdxType i, j;
    int c, q, tipe, x;
    boolean found;

    CreateListDin(&A, 0);

    scanf("%d", &c);
    scanf("%d", &q);

    for(i=0; i<q; i++){
        scanf("%d", &tipe);
        if(tipe == 1){
            scanf("%d", &x);
            for(j=getLastIdx(A); j>=0; j--){
                if (!(ELMT(A, j) >= x)){
                    deleteLast(&A, &ELMT(A,getLastIdx(A)));
                }
            }
            insertLast(&A, x);
        }

        if(tipe == 2){
            printf("%d\n", NEFF(A));
            printList(A);
            printf("\n");
        }
    }
    return 0;
}