#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

void sortWord(Word *word) {
    int i, j;
    char temp;

    for (i = 0; i < word->Length - 1; i++) {
        for (j = i + 1; j < word->Length; j++) {
            if (word->TabWord[i] > word->TabWord[j]) {
                temp = word->TabWord[i];
                word->TabWord[i] = word->TabWord[j];
                word->TabWord[j] = temp;
            }
        }
    }
}

boolean isEqualWord(Word word1, Word word2) {
    if (word1.Length != word2.Length) {
        return false;
    }
    for (int i = 0; i < word1.Length; i++) {
        if (word1.TabWord[i] != word2.TabWord[i]) {
            return false; 
        }
    }
    return true;
}

int countAnagrams(char words[][NMax + 1], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Word word1, word2;

            int k = 0;
            while (words[i][k] != '\0') {
                word1.TabWord[k] = words[i][k];
                k++;
            }
            word1.Length = k;

            k = 0;
            while (words[j][k] != '\0') {
                word2.TabWord[k] = words[j][k];
                k++;
            }
            word2.Length = k;

            sortWord(&word1);
            sortWord(&word2);

            if (isEqualWord(word1, word2)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    STARTWORD();

    char words[100][NMax + 1]; 

    int n = 0;

    while (!EndWord) {
        int i = 0;
        while (i < currentWord.Length) {
            words[n][i] = currentWord.TabWord[i];
            i++;
        }
        words[n][i] = '\0';
        n++;

        ADVWORD();
    }

    int anagramCount = countAnagrams(words, n);

    printf("%d\n", anagramCount);

    return 0;
}
