// Erdianti Wiga Putri Andini
// 13522053
// File : "mtime.c"
// Tanggal : 4 September 2023

#include <stdio.h>
#include <math.h>
#include "time.h"

int main(){
    int N, i;
    long diff;
    TIME start, end, T1, T2, temp;

    scanf("%d", &N);
    CreateTime(&start, 23, 59, 59);
    CreateTime(&end, 0, 0, 0);

    for (i=0; i<N; i++){
        printf("[%d]", i+1);
        printf("\n");
        BacaTIME(&T1);
        BacaTIME(&T2);

        if (TGT(T1,T2)){
            temp = T1;
            T1 = T2;
            T2 = temp;
        }

        diff = Durasi(T1,T2);
        printf("%ld\n", diff);

        if(TLT(T1,start)){
            start = T1;
        }
        
        if(TLT(T2,start)){
            start = T2;
        }
        
        if (TGT(T1,end)){
            end = T1;
        }

        if (TGT(T2,end)){
            end = T2;
        }       
    }
    
    TulisTIME(start);
    printf("\n");
    TulisTIME(end);
    printf("\n"); 

    return 0;
}