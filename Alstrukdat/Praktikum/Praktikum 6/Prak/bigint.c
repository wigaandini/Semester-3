#include <stdio.h>
#include "stack.h"
#include "wordmachine.h"

void printWord(Word word) {
   infotype i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
   printf("\n");
}

int main() {
    Word listWords[100];
    infotype countWord = 0;
    
    START();
    while (currentChar != MARK) {
        ADVWORD();

        listWords[countWord] = currentWord;
        countWord++;
    }

    Stack S1, S2;
    CreateEmpty(&S1);
    CreateEmpty(&S2);

    int i;
    infotype digit;
    for (i = 0; i < listWords[0].Length; i++){
        digit = listWords[0].TabWord[i] - '0';
        Push(&S1, digit);
    }

    for (i = 0; i < listWords[1].Length; i++){
        digit = listWords[1].TabWord[i] - '0';
        Push(&S2, digit);
    }

    Stack diff;
    CreateEmpty(&diff);

    boolean check = false;
    boolean end = true;

    while (!IsEmpty(S2)){
        infotype val1, val2, temp;
        Pop(&S1, &val1);
        Pop(&S2, &val2);
        if (check){
            val1 -= 1;
            check = false;
        }
        if (val1 < val2){
            check = true;
            val1 += 10;
        }
        temp = val1 - val2;
        if (temp != 0){
            end = false;
        }
        Push(&diff, temp);
    }

    while (!IsEmpty(S1)){
        end = false;
        infotype val;
        Pop(&S1, &val);
        if (check) {
            val -= 1;
            check = false;
        }
        Push(&diff, val);
    }

    if (end){
        printf("0\n");
    } 
    else {
        while (InfoTop(diff) == 0){
            infotype temp;
            Pop(&diff, &temp);
        }
        while (!IsEmpty(diff)){
            infotype val;
            Pop(&diff, &val);
            printf("%d", val);
        }
        printf("\n");
    }
}