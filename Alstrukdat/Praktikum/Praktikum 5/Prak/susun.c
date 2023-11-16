#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

int compareWord(Word word1, Word word2) {
    int i = 0;
    while (i < word1.Length && i < word2.Length) {
        if (word1.TabWord[i] < word2.TabWord[i]) {
            return -1;
        } else if (word1.TabWord[i] > word2.TabWord[i]) {
            return 1;
        }
        i++;
    }

    if (word1.Length < word2.Length) {
        return -1;
    } else if (word1.Length > word2.Length) {
        return 1;
    }

    return 0;
}

void sortWords(char words[][NMax + 1], int n) {
    int i, j;
    char temp[NMax + 1];

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
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

            int compareResult = compareWord(word1, word2);

            if (compareResult > 0) {
                int l = 0;
                while (words[i][l] != '\0') {
                    temp[l] = words[i][l];
                    l++;
                }
                temp[l] = '\0';

                l = 0;
                while (words[j][l] != '\0') {
                    words[i][l] = words[j][l];
                    l++;
                }
                words[i][l] = '\0';

                l = 0;
                while (temp[l] != '\0') {
                    words[j][l] = temp[l];
                    l++;
                }
                words[j][l] = '\0';
            }
        }
    }
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

    sortWords(words, n);

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}