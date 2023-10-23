#include <stdio.h>
#include "liststatik.h"
#include <stdlib.h>
#include <math.h>
#include "boolean.h"

int main(){
    ListStatik l1,l2;
    readList(&l1);
    readList(&l2);

    IdxType i;
    for(i=0; i<listLength(l2); i++){
        insertLast(&l1, ELMT(l2,i));
    }
    
    boolean asc = true;
    sortList(&l1,asc);
    printList(l1);
    printf("\n");
    return 0;
}
