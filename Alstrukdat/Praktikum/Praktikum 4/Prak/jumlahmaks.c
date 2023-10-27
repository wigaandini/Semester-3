#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

// ElType sumSub(Matrix m, int startRow, int startCol){
//     ElType sum = 0, max = 0;
//     int i, j, a;
//     for(a=1; a<=ROW_EFF(m)){
//         if(ROW_EFF(m)%a == 0){
//             for(i=startRow;i<startRow+a;i++){
//                 for(j=startCol;j<startCol+(ROW_EFF(m)/a);j++){
//                     sum += ELMT(m,i,j);
//                     if (sum>max){
//                         max = sum;
//                     }
//                 }
//             }
//         }
//     }
//     return max;
// }

int main(){
    int n, m, k, a, startRow, startCol;
    IdxType i, j;
    Matrix m1, sub;

    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    readMatrix(&m1, n, m);

    ElType sum = 0, max = -999, tempsum = 0;
    for(a=1; a<=ROW_EFF(m1); a++){
        if(k%a == 0){
            if(k/a <= ROW_EFF(m1) && k/a <= COL_EFF(m1)){
                for(i=0;i<a;i++){
                    for(j=0;j<(k/a); j++){
                        sum += ELMT(m1,i,j);
                        tempsum = sum;
                        printf("%d\n", sum);
                        if (tempsum>=max){
                            max = sum;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", max);
    return 0;
}