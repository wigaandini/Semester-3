#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int main(){
    Matrix m;
    IdxType i, j;
    int putih = 0, hitam = 0;

    readMatrix(&m, 8, 8);
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            if(i%2 == 0){
                if(ELMT(m, i, j) == 1){
                    if(j%2 != 0){
                        putih ++;
                    }
                    else{
                        hitam++;
                    }
                }
            }
            else{
                if(ELMT(m, i, j) == 1){
                    if(j%2 == 0){
                        putih ++;
                    }
                    else{
                        hitam++;
                    }
                }
            }
        }
    }
    printf("%d %d\n", hitam, putih);
    return 0;
}