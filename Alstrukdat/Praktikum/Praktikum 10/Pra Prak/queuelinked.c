/* File: queuelinked.h */

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "queuelinked.h"

/* Prototype manajemen memori */
Address newNode(ElType x){
    Address P = (Address) malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmpty(Queue q){
    return(ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int length(Queue q){
    int count = 0;
    Address p = ADDR_HEAD(q);
    while (p != NIL) {
        count ++;
        p = NEXT(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueue(Queue *q){
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void DisplayQueue(Queue q){
    Address P = ADDR_HEAD(q);
    printf("[");
    while (P != NULL) {
        printf("%d", INFO(P));
        if (NEXT(P) != NULL) {
            printf(",");
        }
        P = NEXT(P);
    }
    printf("]");
}
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x){
    Address p = newNode(x);
    if (p != NULL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } 
        else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
void dequeue(Queue *q, ElType *x){
    Address P = ADDR_HEAD(*q);
    *x = INFO(P);
    ADDR_HEAD(*q) = NEXT(P);
    if (ADDR_HEAD(*q) == NULL) {
        ADDR_TAIL(*q) = NULL;
    }
    NEXT(P) = NULL;
    free(P);
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */