#include <stdio.h>

int func4(int x){
    if (x < 3)
        return 1;
    else
        return func4(x-1) + func4(x - 2);
}

void Sky_Street(char *input){
    int x, y;
    int val = sscanf(input, "%d %d", &x, &y);
    if (val < 2) { 
        illegal_move();
    }
    x = func4(x);
    if (y != 89){
        illegal_move();
    }
    if (x != 89){
        illegal_move();
    }
    return;
}

/* 11 89 */