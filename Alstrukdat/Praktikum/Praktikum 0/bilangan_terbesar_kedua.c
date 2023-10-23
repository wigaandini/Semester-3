#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int n;
    scanf("%d", &n);
    
    if (n<2){
        return 1;
    }
    int max = -99999, sec = -99999;
    int input, i;
    for (i = 0; i < n; i++){
        scanf("%d", &input);
        if (input > max){
            sec = max;
            max = input;
        }
        else if (input < max && input > sec){
            sec = input;
        }
    }
    printf("%d\n", sec);
    return 0;
}