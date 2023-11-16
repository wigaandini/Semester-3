#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "matrix.h"

void solvePuzzle(Matrix puzzle, int K, Matrix *pieces) {
    boolean solved = true;

    for (int k = 0; k < K; k++) {
        boolean found = false;
        for (int i = 0; i <= getLastIdxRow(puzzle) - getLastIdxRow(pieces[k]); i++) {
            for (int j = 0; j <= getLastIdxCol(puzzle) - getLastIdxCol(pieces[k]); j++) {
                Matrix subPuzzle;
                createMatrix(getLastIdxRow(pieces[k]) + 1, getLastIdxCol(pieces[k]) + 1, &subPuzzle);

                for (int x = 0; x <= getLastIdxRow(pieces[k]); x++) {
                    for (int y = 0; y <= getLastIdxCol(pieces[k]); y++) {
                        ELMT(subPuzzle, x, y) = ELMT(puzzle, i + x, j + y);
                    }
                }

                if (isMatrixEqual(subPuzzle, pieces[k])) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (!found) {
            solved = false;
            break;
        }
    }

    if (solved) {
        printf("Puzzle dapat diselesaikan.\n");
    } else {
        printf("Puzzle tidak dapat diselesaikan.\n");
    }
}

int main() {
    int n, m, K;
    scanf("%d %d", &n, &m);

    Matrix puzzle;
    readMatrix(&puzzle, n, m);

    scanf("%d", &K);

    Matrix pieces[K];
    for (int i = 0; i < K; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        createMatrix(a, b, &pieces[i]);
        readMatrix(&pieces[i], a, b);
    }

    solvePuzzle(puzzle, K, pieces);

    return 0;
}
