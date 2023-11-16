#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"
#include "boolean.h"

int printWord(Word word) {
    int i;
    for (i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
}

boolean compare(Word w1, Word w2) {
    int i;
    if (w1.Length != w2.Length) {
        return false;
    }
    for (i = 0; i < w1.Length; i++){
        if (w1.TabWord[i] != w2.TabWord[i]) {
            return false;
        }
    }
    return true;
}

Word strToWord(char str[], int len) {
    int i;
    Word word;
    word.Length = len;
    for (i = 0; i < len; i++){
        word.TabWord[i] = str[i];
    }
    return word;
}

int main() {
    // KAMUS
    int i, num;

    boolean needSpace, isNum, printNum;
    Word up, left, down, right;

    // ALGORITMA
    scanf("%d", &num);
    STARTWORD();

    char cUp[100] = "MOVEUP";
    up = strToWord(cUp, 6);

    char cLeft[100] = "MOVELEFT";
    left = strToWord(cLeft, 8);

    char cDown[100] = "MOVEDOWN";
    down = strToWord(cDown, 8);

    char cRight[100] = "MOVERIGHT";
    right = strToWord(cRight, 9);

    while (!EndWord) {
        // char num = currentWord.TabWord[0];
        if(compare(left, currentWord)){
            printf("Moving %d square leftwards\n", num);
        }
        else if(compare(down, currentWord)){
            printf("Moving %d square downwards\n", num);
        }
        else if(compare(up, currentWord)){
            printf("Moving %d square upwards\n", num);
        }
        else if(compare(right, currentWord)){
            printf("Moving %d square rightwards\n", num);
        }
        ADVWORD();
    }
    return 0;
}