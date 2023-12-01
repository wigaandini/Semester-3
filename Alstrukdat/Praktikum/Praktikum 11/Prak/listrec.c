/* Erdianti Wiga Putri A */
/* 13522053 */

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

/* Manajemen Memori */
Address newNode(ElType x){
    Address P;
    P = (Address) malloc (sizeof(Node));
    if (P != NIL){
        INFO(P) = x;
        NEXT(P) = NIL;
    }
    return P;

}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
    return (l == NIL);
}
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
boolean isOneElmt(List l){
    return (!isEmpty(l) && isEmpty(tail(l)));
}
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
    return INFO(l);
}
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l){
    return NEXT(l);
}
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e){
    Address P = newNode(e);
    if (P != NIL){
        NEXT(P) = l;
        return P;
    }
    else{
        return l;
    }
}
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e){
    if (isEmpty(l)){
        return newNode(e);
    }
    else{
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
List copy(List l){
    if (isEmpty(l)){
        return NIL;
    }
    else{
        return konso(copy(tail(l)), head(l));
    }

}
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
List concat(List l1, List l2){
    if (isEmpty(l1)){
        return copy(l2);
    }
    else{
        return konso(concat(tail(l1), l2), head(l1));
    }
}
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */

/* Fungsi dan Prosedur Lain */
int length(List l){
    if (isEmpty(l)){
        return 0;
    }
    else{
        return 1 + length(tail(l));
    }
}
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
boolean isMember(List l, ElType x){
    if (isEmpty(l)){
        return false;
    }
    else{
        if (head(l) == x){
            return true;
        }
        else{
            return isMember(tail(l), x);
        }
    }
}
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
void displayList(List l){
    if (!isEmpty(l)){
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx){
    if (idx == 0){
        return konso(l, e);
    }
    else{
        return konso(insertAt(tail(l), e, idx-1), head(l));
    }

}
/* Fungsi untuk menambahkan e sebagai elemen pada posisi/index idx sebuah list l */

List deleteFirst(List l){
    return tail(l);
}
/* Fungsi untuk menghapus elemen pertama sebuah list l */

List deleteAt(List l, int idx){
    if (idx == 0){
        return tail(l);
    }
    else{
        return konso(deleteAt(tail(l), idx-1), head(l));
    }
}
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */

List deleteLast(List l){
    if (isEmpty(tail(l))){
        return NIL;
    }
    else{
        return konso(deleteLast(tail(l)), head(l));
    }
}
/* Fungsi untuk menghapus elemen terakhir sebuah list l */

/*** Operasi-Operasi Lain ***/
List inverseList (List l){
    if (isEmpty(l)){
        return l;
    }
    else if(isOneElmt(l)){
        return l;
    }
    else{   
        return konsb(inverseList(tail(l)),head(l));
    }
}
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void splitPosNeg (List l, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else{
        if (head(l) >= 0){
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1,head(l));
        }
        else{
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2,head(l));
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */

void splitOnX (List l, ElType x, List *l1, List *l2){
    if (isEmpty(l)){
        *l1 = NULL;
        *l2 = NULL;
    }
    else{
        splitOnX(tail(l),x,l1,l2);
        if (head(l) < x){
            *l1 = konso(*l1,head(l));
        }
        else{
            *l2 = konso(*l2, head(l));
        }
    }
}
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */

List removeDuplicate(List l, List unique){
    if (isEmpty(l)){
        return unique;
    }
    else{
        if (!isMember(unique, head(l))){
            unique = konso(unique, head(l));
        }
        return removeDuplicate(tail(l), unique);
    }
}
/* l dan unique terdefinisi, l sembarang dan unique digunakan sebagai tempat menyimpan elemen unik */
/* Mengembalikan list yang berisi elemen unik */
/* Urutan masuk ke dalam list unique menggunakan konso */