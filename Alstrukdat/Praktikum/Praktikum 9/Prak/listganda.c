/* File : listsirkular.h */
/* contoh ADT list sirkular berkait dengan representasi pointer ganda  */

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "listganda.h"

Address newNode(ElType val){
    Address p = (Address) malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
        PREV(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : CURRENT(l) = NULL */
/* CURRENT: Elemen yang ditunjuk saat ini. Karena sirkular, tidak ada elemen pertama ataupun terakhir. */

/* PROTOTYPE */

void createListGanda(ListGanda *l){
    CURRENT(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

boolean isEmpty(ListGanda l){
    return (CURRENT(l) == NULL);
}
/* Mengirim true jika list kosong */

boolean isOneElement(ListGanda l){
    Address p = CURRENT(l);
    return(NEXT(p) == PREV(p));
}
/* Mengirim true jika list terdiri atas 1 elemen saja*/

int length(ListGanda l){
    int count = 0;
    if(isEmpty(l)){
        return 0;
    }
    else{
        Address p = CURRENT(l);
        while(NEXT(p) != PREV(p)){
            count ++;
        }
        return count;
    }
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

void rotate(ListGanda *l, int k){
    Address p = CURRENT(*l);
    if(isEmpty(*l)){
        return NULL;
    }
    else{
        if(k == 0){
            CURRENT(*l) = p;
        }
        else if(k > 0){
            while(k != 0){
                p = NEXT(p);
                if(NEXT(p) == NULL){
                    p = PREV(p);
                    if(PREV(p) == NULL){
                        p = NEXT(p);
                    }
                }
                k --;
            }
            CURRENT(*l) = p;
        }
        else if(k < 0){
            k *= (-1);
            while(k != 0){
                p = PREV(p);
                if(PREV(p) == NULL){
                    p = NEXT(p);
                    if(NEXT(p) == NULL){
                        p = PREV(p);
                    }
                }
                k --;
            }
            CURRENT(*l) = p;
        }
    }
}
/* I.S. l terdefinisi, l mungkin kosong
    k mungkin positif, nol, maupun negatif, abs(k) mungkin lebih besar dari length(l) */
/* F.S. CURRENT menunjuk ke elemen ke-k dari CURRENT sebelumnya
    dengan k positif artinya ke arah NEXT dan k negatif artinya ke arah PREV */

void insertAfterCurrent(ListGanda *l, ElType x){
    Address p, last;
    p = newNode(x);
    if (p != NULL) {
        last = CURRENT(*l);
        while (NEXT(last) != CURRENT(*l)) {
            last = NEXT(last);
        }
        NEXT(last) = p;
        NEXT(p) = CURRENT(*l);
    }
}
/* I.S. l terdefinisi, l mungkin kosong */
/* F.S.
    1. Terbentuk node baru E,
    2. E disisipkan pada NEXT dari CURRENT,
    3. CURRENT menunjuk ke E
 */

void deleteCurrent(ListGanda *l, ElType *x){
    Address p, last;
    p = CURRENT(*l);
    *x = INFO(p);
    if (NEXT(CURRENT(*l)) == CURRENT(*l) && PREV(CURRENT(*l)) == CURRENT(*l)){
        CURRENT(*l) = NULL;
    }
    else{
        last = CURRENT(*l);
        while (NEXT(last) != CURRENT(*l)){
            last = NEXT(last);
        }
        CURRENT(*l) = NEXT(CURRENT(*l));
        NEXT(last) = CURRENT(*l);
    }
}
/* I.S. l terdefinisi, l tidak kosong */
/* F.S.
    1. Elemen CURRENT (E) dikeluarkan dari list,
    2. CURRENT menunjuk pada NEXT dari E
    3. x berisi nilai E
    4. E dihapus
 */