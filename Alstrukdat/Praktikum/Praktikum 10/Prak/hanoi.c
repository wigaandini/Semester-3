/* Nama : Erdianti Wiga Putri Andini */
/* NIM : 13522053 */

#include <stdio.h>
#include <stdlib.h>
#include "stacklinked.h"

void poppush(Stack *s1, Stack *s2){
    ElType val;
    if(!isEmpty(*s1)){
        if (isEmpty(*s2)){
            pop(s1, &val);
            push(s2, val);
        }
        else if(TOP(*s2) > TOP(*s1)){
            pop(s1, &val);
            push(s2, val);
        }
        else{
            printf("Piringan tidak dapat dipindah\n");
        }
    }
    else{
        printf("Menara kosong\n");
    }
}

int main(){
    Stack s1, s2, s3;
    CreateStack(&s1);
    CreateStack(&s2);
    CreateStack(&s3);
    int i, n, si, di;

    for(i = 5; i > 0; i--){
        push(&s1, i);
    }

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d", &si, &di);
        if(si == 1 && di == 2){
            poppush(&s1, &s2);
        }
        else if(si == 1 && di == 3){
            poppush(&s1, &s3);
        }
        else if(si == 2 && di == 3){
            poppush(&s2, &s3);
        }
        else if(si == 2 && di == 1){
            poppush(&s2, &s1);
        }
        else if(si == 3 && di == 1){
            poppush(&s3, &s1);
        }
        else if(si == 3 && di == 2){
            poppush(&s3, &s2);
        }
    }

    printf("Menara 1: "); DisplayStack(s1);
    printf("\nMenara 2: "), DisplayStack(s2);
    printf("\nMenara 3: "), DisplayStack(s3);
    printf("\n");
    return 0;
}