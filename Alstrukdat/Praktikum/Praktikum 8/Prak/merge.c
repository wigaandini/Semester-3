/* Nama : Erdianti Wiga Putri Andini */
/* NIM : 13522053 */

#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>
#include "merge.h"
#include "boolean.h"

void splitList(List source, List* front, List* back){
    int len = length(source);
    int frontPart;
    if(len % 2 == 0){
        frontPart = len / 2;
    }
    else{
        frontPart = ((len / 2) - 1);
    }

    List p = source;
    int i;
    for (i = 0; i < len; i++) {
        if (i <= frontPart) {
            insertLast(front, INFO(p));
        } else {
            insertLast(back, INFO(p));
        }
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
    List result;
    CreateList(&result);

    if (a == NULL){
        return b;
    } 
    else if (b == NULL){
        return a;
    } 
    else {
        List temp1 = a;
        List temp2 = b;
        ElType val;

        while ((temp1 != NULL) && (temp2 != NULL)) {
            if (INFO(temp1) <= INFO(temp2)) 
                deleteFirst(&temp1, &val);
            else 
                deleteFirst(&temp2, &val);
            
            insertLast(&result, val);
        }

        while (temp1 != NULL) {
            deleteFirst(&temp1, &val);
            insertLast(&result, val);
        }

        while (temp2 != NULL) {
            deleteFirst(&temp2, &val);
            insertLast(&result, val);
        }

        return result;
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
    displayList(*list); 
    printf("\n");
    if (length(*list) > 1) {
        List front; 
        List back; 
        CreateList(&front);
        CreateList(&back);

        splitList(*list, &front, &back);
        mergeSort(&front);
        mergeSort(&back);

        List mergesorted = merge(front, back);
        *list = mergesorted;
    }
}
/* Fungsi untuk melakukan inisialisasi merge sort secara rekursif.
   Setiap kali fungsi dipanggil, maka tampilkan list yang sekarang
   sedang diproses.
   Apabila head atau NEXT(head) kosong, maka lakukan return
   Fungsi akan membagi list menjadi dua terlebih dahulu, kemudian 
   secara rekursif melakukan merge untuk mengurutkan
*/