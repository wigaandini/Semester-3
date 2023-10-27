/* File : prioqueuechar.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen prio */

#include "boolean.h"
#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q){
    return (MaxEl(Q) == NBElmt(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueChar Q){
    if (IsEmpty(Q)){
        return 0;
    }
    else {
        if ((Tail(Q) - Head(Q)) >= 0){
            return Tail(Q) - Head(Q) + 1;
        }
        else {
            return MaxEl(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
    (*Q).T = (infotype*)malloc((Max)*sizeof(infotype));
    if((*Q).T == NULL){
        MaxEl(*Q) = 0;
    }
    else{
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
    Tail(*Q) = Nil;
    Head(*Q) = Nil;
    MaxEl(*Q) = 0;
    free((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
    int i, j;
    infotype temp;

    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    }
    else {
        Tail(*Q) = Tail(*Q) == MaxEl(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        if (i == 0){
            j == MaxEl(*Q) - 1;
        }
        else{
            j = i-1;
        }
        while (i != Head(*Q) && Prio(Elmt(*Q, i)) < (Prio(Elmt(*Q, j)))) {
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            if (i == 0){
                j = MaxEl(*Q) - 1;
            }
            else{
                j = i-1;
            }
        }
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueChar * Q, infotype * X){
    if (NBElmt(*Q) == 1) {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        *X = InfoHead(*Q);
        if((Head(*Q) == MaxEl(*Q) - 1)){
            Head(*Q) = 0;
        }
        else{
            Head(*Q) += 1;
        }
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
    infotype val;
    PrioQueueChar new;
    new = Q;
    if(!IsEmpty(Q)){
        while(!IsEmpty(new)){
            Dequeue(&new, &val);
            printf("%d %c\n", Prio(val), Info(val));
        }
    }
    printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/