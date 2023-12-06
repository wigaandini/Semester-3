               temp1[1] = n / j;
                if (max(temp1) < result) {
                    result = max(temp1);
                    step2 = true;
                }
            }
        }
        if(step2){
            fway(result,r,Q,prev);
        }
    }
}

int minimumQueue(Queue *q){
    int result;
    dequeue(q,&result);
    int temp;
    while(!isEmpty(*q)){
        dequeue(q,&temp);
        if(temp < result){
            result = temp;
        }
    }
    return result;
}

int main() { 
    int n;
    scanf("%d", &n);
    int i;
    int temp;
    
    int hasil = 1;
    Queue q;
    int tempR;
    
    for (i = 0; i < n; i++) {
        int r =0;
        CreateQueue(&q);
        scanf("%d",&temp);
        int prev = temp;
        fway(temp,r,&q,&prev);
        int a;
        
        hasil = hasil * prev;
    }
    if(n == 0){
        printf("0\n");
    }else{
        printf("%d\n", hasil);
    }
    
    return 0;
}