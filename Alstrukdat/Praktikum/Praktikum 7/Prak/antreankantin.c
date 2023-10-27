#include <stdio.h>
#include "queue.h"

// float avgElmt(Queue q){
//     float sum = 0;
//     int i;
//     for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i = (i+1)%CAPACITY){
//         sum += q.buffer[i];
//     }
//     return (sum/length(q));
// }

int main(){
    Queue q;
    int pilih, count = 0;
    ElType val;
    ElType sum = 0;
    float avg;
    
    CreateQueue(&q);
    do{
        scanf("%d", &pilih);
        if (pilih == 1){
            scanf("%d", &val);
            if(!isFull(q)){
                enqueue(&q, val);
            }
            else{
                printf("Queue penuh\n");
            }
        }
        else if(pilih == 2){
            if(!isEmpty(q)){
                dequeue(&q, &val);
                sum += val;
                count ++;
            }
            else{
                printf("Queue kosong\n");
            }
        }
    } while (pilih != 0);

    printf("%d\n", count);
    if(pilih == 0){
        if(sum != 0){
            avg = (float) sum/count;
            printf("%.2f\n", avg);
        }
        else{
            printf("Tidak bisa dihitung\n");
        }
    }
}