#include <stdio.h>
#include "stack.h"

void SortirKeranjang(Stack *S1, Stack *S2) {
    CreateEmpty(S2);

    while (!IsEmpty(*S1)) {
        infotype temp;
        Pop(S1, &temp);

        while (!IsEmpty(*S2) && InfoTop(*S2) < temp) {
            infotype larger;
            Pop(S2, &larger);
            Push(S1, larger);
        }

        Push(S2, temp);
    }
}