#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matrix.h"

int main() {
    Matrix mat;
    int N, M, K;

    scanf("%d %d %d", &N, &M, &K);
    readMatrix(&mat, N, M);

    int maxTotal = 0;
    for (int i1 = 0; i1 < N; i1++) {
        for (int j1 = 0; j1 < M; j1++) {
            for (int i2 = i1; i2 < N; i2++) {
                for (int j2 = j1; j2 < M; j2++) {
                    int total = 0;
                    for (int x = i1; x <= i2; x++) {
                        for (int y = j1; y <= j2; y++) {
                            total += ELMT(mat, x, y);
                        }
                    }

                    if ((i2 - i1 + 1) * (j2 - j1 + 1) == K && total > maxTotal) {
                        maxTotal = total;
                    }
                }
            }
        }
    }

    printf("%d\n", maxTotal);

    return 0;
}