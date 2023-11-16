#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

void printWord(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

int main() {
    STARTWORD();

    int charCount = 0;

    while (!EndWord) {
        int i = 0;
        while (i < currentWord.Length) {
            // printf("%c", currentWord.TabWord[i]);
            charCount++;
            i++;
        }

        if (!EndWord) {
            // printf(" ");
            charCount++;
        }

        ADVWORD();
    }

    printf("%d\n", charCount-1);

    return 0;
}
