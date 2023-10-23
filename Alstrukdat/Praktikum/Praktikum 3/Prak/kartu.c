#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "listdin.h"

int main(){
    ListDin t1, t2, tf;
    int i=0, j=0;

    CreateListDin(&t1,100000);
    readList(&t1);

    CreateListDin(&t2,100000);
    readList(&t2);

    CreateListDin(&tf, 200000);

    while(i < listLength(t1) || j < listLength(t2)){
        if(i == listLength(t1)){
            insertLast(&tf, ELMT(t2,j));
            j++;
        }
        else if(j == listLength(t2)){
            insertLast(&tf, ELMT(t1,i));
            i++;
        }
        else{
            if(ELMT(t1,i) >= ELMT(t2,j)){
                insertLast(&tf, ELMT(t1,i));
                i++;
            }
            else{
                insertLast(&tf, ELMT(t2,j));
                j++;
            }
        }
    }

    printList(tf);
    printf("\n");
    return 0;
}