#include "queue.h"
#include <stdio.h>

int main() {
    Queue q;
    CreateQueue(&q);

    int n, k, val, i;
    scanf("%d", &n);
    scanf("%d", &k);

    while (n > 0) {
        scanf("%d", &val);
        enqueue(&q, val);
        n--;
    }

    int temp[k];
    for (i = 0; i < k; i++) {
        temp[i] = q.buffer[i];  
    }

    for (i = 0; i < k; i++) {
        q.buffer[i] = temp[k - i - 1];
    }

    displayQueue(q);
    return 0;
}
