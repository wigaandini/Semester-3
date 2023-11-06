#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

int main(){
    List l;
    int n, i;
    Address p;

    scanf("%d", &n);
    CreateList(&l);

    for(i = 0; i < n; i++){
        insertLast(&l, i+1);
    }

    int temp = 0;
    int val, ai;
    Address loc;
    ElType del;
    int length = n;
    while(temp < n-1){
        temp++; 
        scanf("%d", &ai); 
        loc = FIRST(l);
        if(ai > 0){
            val = ai;
            while (val > 1){
                loc = NEXT(loc);
                val--;
            }
            if(ai == 1){
                deleteFirst(&l, &val);
            }
            else{
                loc = NEXT(loc);
                del = INFO(loc);
                FIRST(l) = loc;
                // printf("%d\n", del);
                deleteFirst(&l,&val);
            }
            // displayList(l);
            // printf("\n");
            length --;
        }
        else if (ai < 0){
            val = length - (ai * (-1));
            while(val > 1){
                loc = NEXT(loc);
                // while(NEXT(loc) != FIRST(l)){
                //     loc = NEXT(loc);
                // }
                val --;
            }
            loc = NEXT(loc);
            del = INFO(loc);

            FIRST(l) = loc;
            // printf("%d\n", del);
            deleteFirst(&l, &val);
            // displayList(l);
            // printf("\n");
            length --;
    }
        if(temp == n-1){
            printf("%d\n", del);
        }
    }
    return 0;
}