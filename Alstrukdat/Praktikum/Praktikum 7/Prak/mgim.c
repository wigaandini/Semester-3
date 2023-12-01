#include "queue.h"
#include <stdio.h>

int main(){
    int N, Ni;
    int result = 1; // Initialize result with 1

    // Input the number of elements
    scanf("%d", &N);

    // Process each Ni
    for (int i = 0; i < N; i++){
        Queue q;
        CreateQueue(&q);

        scanf("%d", &Ni);

        enqueue(&q, Ni);

        int Ri = 1;
        while (!isEmpty(q)){
            int val;
            dequeue(&q, &val);
            if (val > 0){
                enqueue(&q, val - 1);
            }
            Ri++;
        }

        result *= Ri;
    }

    printf("%d\n", result);

    return 0;
}