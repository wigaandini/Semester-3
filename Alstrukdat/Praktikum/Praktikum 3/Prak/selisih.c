#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "listdin.h"

int main(){
    ListDin l;
    ElType max, min, selisih;
    IdxType i;
    CreateListDin(&l, 100);

    readList(&l);
    if (listLength(l) <= 1){
        selisih = 0;
    }
    else{
        extremeValues(l, &max, &min);
        max += 1;
        selisih = max - min;
    }

    printf("%d\n", selisih);
    return 0;
}