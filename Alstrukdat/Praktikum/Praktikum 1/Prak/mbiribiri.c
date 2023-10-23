#include <stdio.h>
#include "point.h"
#include "boolean.h"
#include "garis.h"
#include <math.h>
// #include "point.c"
// #include "garis.c"

int main(){
    int n, i, b, count = 0;
    POINT P;
    GARIS L;
    float d;
 
    scanf("%d", &b);
    BacaGARIS(&L);
    scanf("%d", &n);

    for (i=1; i<=n; i++){
        BacaPOINT(&P);
        d = fabs(JarakGARIS(L,P));
        // printf("%f", d);
        if (d <= b){
            count += 1;
        }
    }
    printf("%d\n", count);
    return 0;
}