#include "listrec.h"
#include "sort.h"
#include <stdio.h>

void splitList(List source, List* front, List* back) {
    int len = length(source);
    int frontPart;
    if(len % 2 == 0){
        frontPart = len / 2;
    } 
    else {
        frontPart = (len / 2) - 1;
    }

    Address p = source;
    int i;
    for (i = 0; i < len; i++) {
        if (i <= frontPart) {
            *front = konsb(*front, INFO(p));
        } 
        else {
            *back = konsb(*back, INFO(p));
        }
        p = NEXT(p);
    }
}

Address findMiddle(List l){
    int len = length(l);
    int middle;
    if(len % 2 == 0){
        middle = len / 2;
    } 
    else {
        middle = (len / 2) - 1;
    }
    int i;
    Address p = l;
    for (i = 0; i < middle; i++) {
        p = tail(p);
    }
    return p;
}
/* Fungsi untuk mencari middle dari list l.
   Fungsi akan mengembalikan Address dari middle tersebut.
   Apabila list ganjil, maka middle adalah elemen tengah.
   Apabila list genap, maka middle adalah elemen tengah kiri.
*/

List merge(List l1, List l2){
    List result = NULL;
    if (l1 == NULL){
        return l2;
    }
    else if (l2 == NULL){
        return l1;
    } 
    else {
        List temp1 = l1;
        List temp2 = l2;
        ElType val;

        while ((temp1 != NULL) && (temp2 != NULL)) {
            if (INFO(temp1) <= INFO(temp2)) {
                val = INFO(temp1);
                temp1 = tail(temp1);
            } else {
                val = INFO(temp2);
                temp2 = tail(temp2);
            } 
            result = konsb(result, val);
        }

        while (temp1 != NULL) {
            val = INFO(temp1);
            temp1 = tail(temp1);
            result = konsb(result, val);
        }

        while (temp2 != NULL) {
            val = INFO(temp2);
            temp2 = tail(temp2);
            result = konsb(result, val);
        }

        return result;
    }
}
/* melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
*/

List mergeSort(List l){
    if (length(l) <= 1){
        return l;
    }
   
    List front = NULL;
    List back = NULL;

    splitList(l, &front, &back);
    front = mergeSort(front);
    back = mergeSort(back);

    return merge(front, back);
}
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Apabila head atau NEXT(head) kosong, maka mengembalikan list tersebut.
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian
   secara rekursif melakukan merge untuk mengurutkan.
*/

List getInit(List l, ElType* last) {
    Address p = l;
    List result = NULL;
    
    while (p != NULL) {
        if (NEXT(p) == NULL) {
            *last = INFO(p);
        } else {
            result = konsb(result, INFO(p));
        }
        p = NEXT(p);
    }

    return result;
}

List zigZagSort(List l) {
    List copy = mergeSort(l);
   
    List result = NULL;
    ElType last;

    int i = 1;
    while (!isEmpty(copy)) {
        if (i % 2) {
            result = konsb(result, head(copy));
            copy = tail(copy);
        } 
        else {
            copy = getInit(copy, &last);
            result = konsb(result, last);
        }
        i += 1;
    }
    return result;
}
/* Fungsi untuk melakukan zig-zag sort.
   Zig-zag sort adalah suatu teknik pengurutan dengan cara
   mengurutkan elemen-elemen dengan pola:
   terbesar 1 - terkecil 1 - terbesar 2 - terkecil 2 .. dst.
   Contoh:
   8 1 5 2 3
   8 1 4 2 3
*/