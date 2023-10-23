#include <stdio.h>
#include "liststatik.h"
#include <stdlib.h>
#include <math.h>
#include "boolean.h"

int main(){
    ListStatik r, p;
    IdxType i, j, k;
    int idx1=0, idx2=0, idx3=0, sum1=0, sum2=0, sum3=0, sum=0; 

    readList(&r);
    readList(&p);

    for(i=0; i<listLength(r); i++){
        if(ELMT(r,i) == 1){
            idx1 = i;
        }
        if(ELMT(r,i) == 2){
            idx2 = i;
        }
        if(ELMT(r,i) == 3){
            idx3 = i; 
        }
    }

    for(i=0; i<=idx1; i++){
        if (ELMT(r,i) == 1){
            if (i!=0){
                sum1 += 1;
                sum1 += (ELMT(p,i-1)*2);
            }
            else{
                sum1 += 1;
            }
        }
        else{
            if (i!=0){
                sum1 += (ELMT(p,i-1)*2);
            }
        }
    }

    for(j=0; j<=idx2; j++){
        if (ELMT(r,j) == 2){
            if (j!=0){
                sum2 += 1;
                sum2 += (ELMT(p,j-1)*2);
            }
            else{
                sum2 += 1;
            }
        }
        else{
            if (j!=0){
                sum2 += (ELMT(p,j-1)*2);
            }
        }
    }
    
    for(k=0; k<=idx3; k++){
        if (ELMT(r,k) == 3){
            if (k!=0){
                sum3 += 1;
                sum3 += (ELMT(p,k-1)*2);
            }
            else{
                sum3 += 1;
            }
        }
        else{
            if (k!=0){
                sum3 += (ELMT(p,k-1)*2);
            }
        }
    }

    sum = sum1 + sum2 + sum3;

    printf("%d\n", sum);
    return 0;
}