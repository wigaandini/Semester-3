/* Nama : Erdianti Wiga Putri Andini */
/* NIM : 13522053 */

#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>
#include "merge.h"
#include "boolean.h"

void splitList(List source, List* front, List* back){
    CreateList(front);
    CreateList(back);
    int half;
    if (length(source)%2 == 0){
        half = length(source)/2;
    }
    else{
        half = (length(source)/2) + 1;
    }
    int count = 0;
    Address p = source;
    while(p != NULL){
        if(count < half){
            insertLast(front, INFO(p));
        }
        else{
            insertLast(back, INFO(p));
        }
        count++;
        p = NEXT(p);
    }
}
/* Fungsi untuk memecah sebuah list dengan head source menjadi dua buah 
   list baru, yaitu front dan back. Apabila panjang list ganjil, maka
   list front akan lebih panjang dibandingkan list back.
   Sebagai contoh untuk list dengan panjang 5, maka list front memiliki
   3 elemen dan list back memiliki 2 elemen.
*/

List merge(List a, List b){
    if(isEmpty(a)){
        return b;
    }
    else if(isEmpty(b)){
        return a;
    }
    else{
        Address pa = FIRST(a);
        Address pb = FIRST(b);
        List new;
        CreateList(&new);
        while(pa != NULL){
            if(INFO(pa) <= INFO(pb)){
                insertLast(&new, INFO(pa));
                pa = NEXT(pa);
            }
            else if(INFO(pa) > INFO(pb)){
                insertLast(&new, INFO(pb));
                pb = NEXT(pb);
            }
        }
        return new;
    }
}
/* Fungsi untuk melakukan merge sort list a dan b secara rekursif.
   Sort dilakukan secara ascending berdasarkan nilai elemen.
   Apabila List a = NULL, maka kembalikan List b
   Apabila List b = NULL, maka kembalikan List a
   Selain itu, lakukan perbandingan antara INFO(a) dengan 
   INFO(b) untuk mendapatkan urutannya
*/

void mergeSort(List* list){
    displayList(list);

    List a, b, new;
    CreateList(&a);
    CreateList(&b);
    CreateList(&new);

    splitList(list, &a, &b);

    Address pa = a;
    Address pb = b;
    while (pa != NULL){
        new = merge(a,b);
        displayList(new);
    }
}
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/