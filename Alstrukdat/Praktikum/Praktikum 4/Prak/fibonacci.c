#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix identityMatrix2x2() {
    Matrix identitas;
    createMatrix(2, 2, &identitas);
    ELMT(identitas, 0, 0) = 1;
    ELMT(identitas, 0, 1) = 0;
    ELMT(identitas, 1, 0) = 0;
    ELMT(identitas, 1, 1) = 1;
    return identitas;
}

Matrix pangkatMatrix(Matrix m, long long pangkat, int mod) {
    if (pangkat == 0)
        return identityMatrix2x2();
    else if (pangkat == 1)
        return m;
    else {
        Matrix m2 = pangkatMatrix(m, pangkat / 2, mod);
        Matrix mulMatrix = multiplyMatrixWithMod(m2, m2, mod);

        if (pangkat % 2 == 1)
            mulMatrix = multiplyMatrixWithMod(mulMatrix, m, mod);

        return mulMatrix;
    }
}

int main() {
    long long K;
    scanf("%lld", &K);

    Matrix basis;
    createMatrix(2, 2, &basis);

    ELMT(basis, 0, 0) = 1;
    ELMT(basis, 0, 1) = 1;
    ELMT(basis, 1, 0) = 1;
    ELMT(basis, 1, 1) = 0;

    Matrix resultMatrix = pangkatMatrix(basis, K - 1, 2003);

    printf("%lld\n", ELMT(resultMatrix, 0, 0));

    return 0;
}
