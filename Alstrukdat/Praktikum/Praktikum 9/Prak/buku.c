#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

int main() {
    int n, temp, i, j, result = 1;
    List l;
    CreateList(&l);
    scanf("%d", &n);
    boolean b[n];
    for (i = 0; i < n; i++) {
        b[i] = true;
    }
    for (i = 0; i < n-1; i++) {
        scanf("%d", &temp);
        insertLast(&l, temp);
    }
    for(i = 0; i < n - 1; i++) {
        deleteFirst(&l, &temp);

        if (temp > 0) {
            for (j = 0; j < temp; j++) {
                result++;
                if (result > n) {
                    result = 1;
                }
                while (!b[result-1]) {
                    result++;
                    if (result > n) {
                        result = 1;
                    }
                }
            }
            result = result % n;
            if (result == 0) {
                result = n;
            }
            if (b[result-1]) {
                b[result-1] = false;
            }
        }

        else {
            temp *= -1;
            for (j = 0; j < temp; j++) {
                result--;
                if (result < 1) {
                    result = n;
                }
                while (!b[result-1]) {
                    result--;
                    if (result < 1) {
                        result = n;
                    }                  
                }
            }
            result = result % n;
            if (result == 0) {
                result = n;
            }
            if (b[result-1]) {
                b[result-1] = false;
            }
        }
    }
    for(j = 0; j < n; j++) {
        if (b[j]) {
            printf("%d\n", j+1);
            break;
        }
    }
}
