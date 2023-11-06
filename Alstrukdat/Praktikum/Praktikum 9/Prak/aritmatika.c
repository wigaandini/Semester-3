/* Nama : Erdianti Wiga Putri Andini */
/* NIM : 1352053 */

#include <stdio.h>
#include "list_circular.h"
#include <stdlib.h>

int main(){
    List l;
    CreateList(&l);

    int n, i;
    scanf("%d", &n);

    ElType el;
    for(i = 1; i <= n; i++){
        scanf("%d", &el);
        insertLast(&l, el);
    }

    Address p = FIRST(l);
    int j = 1;
    int a = 0, b = 0;
    int temp;
    b = INFO(p);
    p = NEXT(p);
    j ++;
    temp = (INFO(p) - b)/(j-1);
    boolean same = true;
    while (NEXT(p) != FIRST(l) && same){
        p = NEXT(p);
        j ++;
        a = (INFO(p) - b)/(j-1);
        if(a == temp){
            same = true;
        }
        else{
            same = false;
        }
    }
    if (same){
        printf("%d %d\n", temp, b);
    }
    else{
        printf("%d %d\n", 0, 0);
    }
    return 0;
} 