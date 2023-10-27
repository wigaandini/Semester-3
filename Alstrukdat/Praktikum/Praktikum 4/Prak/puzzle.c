#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

boolean exist(Matrix m, Matrix subm){
    int startRow=0, startCol=0;
    boolean ex;
    if((ROW_EFF(subm) > ROW_EFF(m)) || (COL_EFF(subm) > COL_EFF(m))){
        return false;
    }
    else{
        while(startRow<ROW_EFF(m)-ROW_EFF(subm)+1 && ex){
            while(startCol<COL_EFF(m)-COL_EFF(subm)+1 && ex){
                if (ELMT(m, startRow, startCol) != ELMT(subm, startRow, startCol)){
                    ex = false;
                }
                else{
                    ex = true;
                    startCol ++;
                }
            }
            startRow++;
        }
        return ex;
    }
}

int main(){
    int n, m, k, a, b;
    IdxType i=0;
    Matrix m1, sub;
    boolean bisa = true;

    scanf("%d", &n);
    scanf("%d", &m);
    readMatrix(&m1, n, m);
    scanf("%d", &k);
    scanf("%d", &a);
    scanf("%d", &b);

    for(i=0; i<k; i++){
        readMatrix(&sub, a, b);
        if(exist(m1, sub)){
            bisa = true;
        }
        else{
            bisa = false;
        }
    }

    if(bisa){
        printf("Puzzle dapat diselesaikan.\n");
    }
    else{
        printf("Puzzle tidak dapat diselesaikan.\n");
    }

    return 0;
}