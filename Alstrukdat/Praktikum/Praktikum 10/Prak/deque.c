#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "deque.h"

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
boolean isEmpty(Deque q){
    return(ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL);
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
int length(Deque q){
    int count = 0;
    Address p = ADDR_HEAD(q);
    while (p != NIL) {
        count ++;
        p = NEXT(p);
    }
    return count;
}
/* Mengirimkan banyaknya elemen Deque. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateDeque(Deque *q){
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void DisplayDeque(Deque q){
    Address p = ADDR_HEAD(q);
    printf("[");
    while (p != NIL) {
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p != NIL) {
            printf(",");
        }
    }
    printf("]");
}
/* Proses : Menuliskan isi Deque, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Deque kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void EnqueueHead(Deque *q, ElType x){
    Address p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_TAIL(*q) = p;
            ADDR_HEAD(*q) = p;
        }
        else{
            NEXT(p) = ADDR_HEAD(*q);
            ADDR_HEAD(*q) = p;
        }
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian HEAD dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertFirst */
/* I.S. q mungkin kosong */
/* F.S. x menjadi HEAD, HEAD "maju" */
void DequeueHead(Deque *q, ElType *x){
    Address p = ADDR_HEAD(*q);
    *x = INFO(p);
    ADDR_HEAD(*q) = NEXT(p);
    if (ADDR_HEAD(*q) == NIL) {
        ADDR_TAIL(*q) = NIL;
    }
    free(p);
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
void EnqueueTail(Deque *q, ElType x){
    Address p = newNode(x);
    if (p != NIL) {
        if (ADDR_TAIL(*q) == NIL) {
            ADDR_HEAD(*q) = p;
        } 
        else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian TAIL dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi TAIL, TAIL "mundur" */
void DequeueTail(Deque *q, ElType *x){
    Address p = ADDR_HEAD(*q);
    if (ADDR_HEAD(*q) == ADDR_TAIL(*q)) {
        *x = INFO(ADDR_HEAD(*q));
        ADDR_HEAD(*q) = NIL;
        ADDR_TAIL(*q) = NIL;
        free(p);
    } 
    else {
        while (NEXT(p) != ADDR_TAIL(*q)) {
            p = NEXT(p);
        }
        *x = INFO(ADDR_TAIL(*q));
        free(ADDR_TAIL(*q));
        ADDR_TAIL(*q) = p;
        NEXT(p) = NIL;
    }
}
/* Proses: Menghapus x pada bagian TAIL dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteLast */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen TAIL pd I.S., TAIL "maju" */