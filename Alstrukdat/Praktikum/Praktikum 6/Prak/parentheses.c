#include <stdio.h>
#include "stack.h"
#include "charmachine.h"
#include "wordmachine.h"

int main() {
    Word input;
    Stack open;
    CreateEmpty(&open);
    STARTWORD();
    input = currentWord;

    int depth = 0;
    int maxDepth = 0;

    for (int i = 0; i < input.Length; i++) {
        char currentChar = input.TabWord[i];

        if (currentChar == '(') {
            Push(&open, currentChar);
            depth++;
            if (depth > maxDepth) {
                maxDepth = depth;
            }
        } else if (currentChar == ')') {
            if (!IsEmpty(open)) {
                Pop(&open, &currentChar);
                depth--;
            } else {
                printf("-1\n");
                return 0;
            }
        }
    }

    if (!IsEmpty(open)) {
        printf("-1\n");
    } else {
        printf("%d\n", maxDepth);
    }

    return 0;
}
