#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int a, b, digit_akhir, i, j, benar, count=0, digit;
    scanf("%d", &a);
    scanf("%d", &b);

    i = a;
    while (i <= b){
        digit_akhir = i%10; 
        benar = 1;
        j=i;

        while (benar == 1 && j != 0){
            digit = j%10;
            if (digit_akhir != digit){
                benar = 0;
            }
            j /= 10;
        }

        if (benar == 1){
            count ++;
        }

        i++;
    }

    printf("%d\n", count);
    return 0;
}