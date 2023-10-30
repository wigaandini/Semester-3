/* Nama : Erdianti Wiga Putri Andini */
/* NIM : 13522053 */

#include <stdio.h>
#include "listlinier.h"

int main(){
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);

    List l;
    CreateList(&l);

    if(q == 0){
        printf("hit ratio: %.2f\n", 0);
    }
    else{
        int i;
        ElType el, val;
        float hitCount = 0;
        for(i = 0; i < q ; i++){
            scanf("%d", &el);
            if(isEmpty(l)){
                if(length(l) < n){
                    insertFirst(&l, el);
                }
                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else if(indexOf(l,el) != IDX_UNDEF){
                deleteAt(&l, indexOf(l,el), &val);
                insertFirst(&l, val);
                printf("hit ");
                displayList(l);
                printf("\n");
                hitCount ++;
            }
            else if(length(l) == n){
                deleteLast(&l, &val);
                insertFirst(&l, el);
                printf("miss ");
                displayList(l);
                printf("\n");
            }
            else{
                insertFirst(&l, el);
                printf("miss ");
                displayList(l);
                printf("\n");
            }
        }
        float ratio = hitCount/q;
        printf("hit ratio: %.2f\n", ratio);
    }
    return 0;
}