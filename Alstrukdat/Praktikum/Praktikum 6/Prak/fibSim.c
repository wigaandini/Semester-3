#include <stdio.h>
#include "stack.h"

int fibonacci(int n) {
    printf("fibonacci(%d)\n", n);

    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, fib;
    scanf("%d", &n);

    fib = fibonacci(n);
    printf("%d\n", fib);

    return 0;
}