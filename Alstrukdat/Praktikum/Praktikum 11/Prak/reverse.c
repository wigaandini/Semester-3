#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

int main() {
    List l1 = NULL, l2 = NULL, result = NULL;
    int n, i, temp, q, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        result = konsb(result, temp);
    }
    int length = n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &q);
        for (j = 0; j < q; j++) {
            l1 = konso(l1, head(result));
            result = tail(result);
        }
        for (j = 0; j < length-q; j++) {
            l2 = konso(l2, head(result));
            result = tail(result);
        }
        result = NULL;        
        for (k = 0; k < length; k++) {
            if (!isEmpty(l1)) {
                result = konsb(result, head(l1));
                l1 = tail(l1);
            }
            else if (!isEmpty(l2)) {
                result = konsb(result, head(l2));
                l2 = tail(l2);
            }
        }
        l1 = NULL;
        l2 = NULL;
    }
    displayList(result);
    return 0;
}