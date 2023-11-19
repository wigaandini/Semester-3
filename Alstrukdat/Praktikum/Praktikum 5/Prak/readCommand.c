#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

// Prints word from Mesin Kata
void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

int main() {
    Word word;
    int i = 0;
    
    START();
    IgnoreBlanks();
    while (currentChar != MARK) {
        word.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    
    if (i > NMax) {
        word.Length = NMax;
    }
    else {
        word.Length = i;
    }

    int count = word.Length;
    printWord(word);
    printf("\n%d\n", count);

    return 0;
}