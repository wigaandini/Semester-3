/* Nama : Erdianti Wiga Putri Andini */
/* NIM : 13522053 */

#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>
#include "merge.h"
#include "boolean.h"

void splitList(List source, List* front, List* back){
    int len = length(source);
    int half = (len - 1) / 2;

    CreateList(front);
    CreateList(back);
    if(len == 0) return;

    Address ad = source;
    for(int i = 0; i <= half; ++i){
        insertLast(front, INFO(ad));
        ad = NEXT(ad);
    }

    for(int i = half + 1; i < len; ++i){
        insertLast(back, INFO(ad));
        ad = NEXT(ad);
    }
}
/* Fungsi untuk memecah sebuah list dengan head source menjadi dua buah 
   list baru, yaitu front dan back. Apabila panjang list ganjil, maka
   list front akan lebih panjang dibandingkan list back.
   Sebagai contoh untuk list dengan panjang 5, maka list front memiliki
   3 elemen dan list back memiliki 2 elemen.
*/

List merge(List a, List b){
    List result;
    CreateList(&result);

    Address l1 = a;
    Address l2 = b;
    while(l1 != NULL && l2 != NULL){
        if(INFO(l1) < INFO(l2)){
            insertLast(&result, INFO(l1));
            l1 = NEXT(l1);
        } else {
            insertLast(&result, INFO(l2));
            l2 = NEXT(l2);
        }
    }

    while(l1 != NULL){
        insertLast(&result, INFO(l1));
        l1 = NEXT(l1);
    }

    while(l2 != NULL){
        insertLast(&result, INFO(l2));
        l2 = NEXT(l2);
    }

    return result;
}
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/

void mergeSort(List* list){
    List front;
    List back;
    if((*list) == NULL) return;
    if((*list)->next == NULL){
        displayList(*list);
        printf("\n");
        return;
    }
    
    splitList(*list, &front, &back);

    displayList(*list);
    printf("\n");

    mergeSort(&front);
    mergeSort(&back);

    *list = merge(front, back);
}
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/