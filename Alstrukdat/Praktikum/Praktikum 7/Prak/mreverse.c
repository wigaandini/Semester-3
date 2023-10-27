#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "queue.h"

int main(){
    int n, k;
    ElType val;
    scanf("%d", &n);
    scanf("%d", &k);

    int i=0, j;
    Queue q, temp, new;
    CreateQueue(&q);
    CreateQueue(&temp);
    CreateQueue(&new);

    while(!isFull(q) && i < n){
        scanf("%d", &val);
        enqueue(&q, val);
        i++;
    }

    for(j = 0; j < k; j++){
        dequeue(&q, &val);
        enqueue(&temp, val);
    }

    for(j = k; j >= 0; j--){
        enqueue(&new, temp.buffer[j]);
    } 

    while(!isFull(new) && !isEmpty(q)){
        dequeue(&q, &val);
        enqueue(&new, val);
    }

    dequeue(&new, &val);
    displayQueue(new);
}