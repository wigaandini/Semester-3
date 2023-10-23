#include <stdio.h>
#include "liststatik.h"
#include <stdlib.h>
#include <math.h>
#include "boolean.h"

int main(){
    ListStatik l1,l2, l3;
    int sum=0, sisa=0, digit=0, num;
    IdxType i;

    readList(&l1);
    readList(&l2);

    for(i=0; i<listLength(l1); i++){
        sum += (ELMT(l1,i) * (pow(10,listLength(l1)-1-i)));
    }

    for(i=0; i<listLength(l2); i++){
        sum += (ELMT(l2,i) * (pow(10,listLength(l2)-1-i)));
    }

    CreateListStatik(&l3);

    // sisa = sum;
    // while (sisa != 0){
    //     sisa /= 10;
    //     digit++;
    // }

    // for(i=0; i<digit; i++){
    //     num = sum/(pow(10,digit-1-i));
    //     insertLast(&l3, num%10);
    //     num/=10;
    // }

    while (sum > 0){
        insertFirst(&l3, sum % 10);
        sum /= 10;
    }

    printList(l3);
    printf("\n");
    return 0;  
}