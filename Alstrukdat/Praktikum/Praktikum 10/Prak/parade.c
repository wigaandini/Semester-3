#include <stdio.h>
#include "stacklinked.h"

int main(){
    int t; scanf("%d", &t);
    for (t; t > 0; t--){
        Stack datang, jalan, parkir;
        CreateStack(&datang);
        CreateStack(&jalan);
        CreateStack(&parkir);

        int n;
        scanf("%d", &n);
        int i;
        int arr[n];

        for (i = 0; i < n; i++){
            int temp;
            scanf("%d", &temp);
            arr[n-i-1] = temp;
        }

        for (i = 0; i < n; i++){
            push(&datang, arr[i]);
        }
        boolean avail = true;
        int current = 1;
        int unavail;
        while ((length(datang) > 0 || length(jalan) > 0) && avail)
        {
            if (!isEmpty(datang) ){
                if (TOP(datang) == current){
                    push(&parkir, TOP(datang));
                    pop(&datang, &unavail);
                    current++;
                    continue;
                }
            } 
            
            if (!isEmpty(jalan)){
                if (TOP(jalan) == current){
                    push(&parkir, current);
                    pop(&jalan, &unavail);
                    current++;
                    continue;
                }
            }

            if (!isEmpty(datang)){
                pop(&datang, &unavail);
                push(&jalan, unavail);
                continue;
            }
            avail = false;
        }

        if (avail){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}