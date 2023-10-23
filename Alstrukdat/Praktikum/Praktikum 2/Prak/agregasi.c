#include <stdio.h>
#include "liststatik.h"
#include <stdlib.h>
#include <math.h>
#include "boolean.h"

int main(){
    ListStatik l;
    IdxType i, idx, idx_med;
    ElType min, max;
    int x, count=0;
    float sum=0;
    float avg;
    boolean asc = true, med;

    readList(&l); 
    scanf("%d", &x);

    sortList(&l,asc);
    printList(l);
    printf("\n");

    for(i=0; i<listLength(l); i++){
        sum += ELMT(l,i);
    }
    avg = sum/listLength(l);

    printf("Average: %.2f\n", avg);

    if (indexOf(l, x) != IDX_UNDEF){
        printf("%d\n", indexOf(l, x));
        ElType max,min;
        extremeValues(l, &max, &min);
        if (x == max)
        {
            printf("X maksimum\n");
        }
        if (x == min)
        {
            printf("X minimum\n");
        }
        if (listLength(l) % 2 == 0 && x == ELMT(l, (listLength(l) / 2)-1))
        {
            printf("X median\n");
        }
        if (listLength(l) % 2 == 1 && x == ELMT(l, (listLength(l) / 2)))
        {
            printf("X median\n");
        }
    }
    else{
        printf("%d tidak ada\n", x);
    }
    return 0;
}