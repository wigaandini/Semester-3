/* Nama : Erdianti Wiga Putri Andini */
/* NIM  : 13522053 */
/* File : bintree.c */
/* ADT pohon biner */

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    Address t = newTreeNode(root);
    if (t != NULL) {
        LEFT(t) = left_tree;
        RIGHT(t) = right_tree;
    }
    return t;
}
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = newTreeNode(root);
    if (*p != NULL) {
        LEFT(*p) = left_tree;
        RIGHT(*p) = right_tree;
    }
}
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val){
    Address p;
    p = (Address) malloc (sizeof(TreeNode));
    if (!isTreeEmpty(p)){
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p){
    free(p);
}
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (BinTree p){
    return (p == NULL);
}
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p){
    return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p){
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p){
    return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p){
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */
void printPreorder(BinTree p){
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
        printf(")");
    }
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

void printInorder(BinTree p){
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
        printf(")");
    }
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

void printPostorder(BinTree p){
    if(isTreeEmpty(p)){
        printf("()");
    }
    else{
        printf("(");
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
        printf(")");
    }
}
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */

void printTreeChild(BinTree p, int h, int childCount){
    if (p!=NULL){
        int i, space = h * childCount;
        for (i = 0; i < space; i++){
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        childCount++;
        printTreeChild(LEFT(p), h, childCount);
        printTreeChild(RIGHT(p), h, childCount);
    }
}

void printTree(BinTree p, int h){
    if(p != NULL){
        printTreeChild(p, h, 0);
    }
}
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/

int hitungNode(BinTree root){
    int count = 0;
    if(isTreeEmpty(root)){
        count += 0;
    }
    else if(isOneElmt(root)){
        count += 0;
    }
    // else if(isBinary(root)){
    //     count += 0;
    //     hitungNode(RIGHT(root));
    //     hitungNode(LEFT(root));
    // }
    else if(isUnerLeft(root)){
        count += 1 + hitungNode(LEFT(root));
    }
    else if(isUnerRight(root)){
        count += 1 + hitungNode(RIGHT(root));
    }
    else{
        count += hitungNode(RIGHT(root)) + hitungNode(LEFT(root));
    }
    return count;
}
// Menerima sebuah pohon biner
// Mengembalikan jumlah minimum node yang perlu ditambahkan


int calculateRoute(BinTree node, int n) {
    if (node == NULL) {
        return 0;
    }

    if (isTreeEmpty(LEFT(node)) && isTreeEmpty(RIGHT(node))) {
        // Leaf node
        if (ROOT(node) == n) {
            return ROOT(node) % 10000;
        } else {
            return 0;
        }
    }

    int leftResult = calculateRoute(LEFT(node), n - ROOT(node));
    int rightResult = calculateRoute(RIGHT(node), n - ROOT(node));

    return (leftResult + rightResult) % 10000;
}

int hitungBebek(BinTree root, int n) {
    return calculateRoute(root, n);
}
// Menerima sebuah pohon biner
// Mengembalikan penjumlahan dari hasil kali antara bebek-bebek pada rute 


int max(int a, int b) {
    return (a > b) ? a : b;
}

int calculateMaxMoney(BinTree node, int stealCurrent) {
    if (node == NULL) {
        return 0;
    }

    if (stealCurrent) {
        // If stealing from the current house, skip adjacent houses
        return ROOT(node) + calculateMaxMoney(LEFT(node), 0) + calculateMaxMoney(RIGHT(node), 0);
    } else {
        // If not stealing from the current house, consider both options for adjacent houses
        int stealLeft = calculateMaxMoney(LEFT(node), 1) + calculateMaxMoney(RIGHT(node), 1);
        int skipLeft = calculateMaxMoney(LEFT(node), 0) + calculateMaxMoney(RIGHT(node), 0);

        return max(stealLeft, skipLeft);
    }
}

int hitungUang(BinTree root) {
    // Start with considering both options for the root node
    int stealRoot = calculateMaxMoney(root, 1);
    int skipRoot = calculateMaxMoney(root, 0);

    // Return the maximum amount of money that can be stolen
    return max(stealRoot, skipRoot);
}
// Menerima sebuah pohon biner yang menyatakan denah perumahan

// Mengembalikan jumlah maksimum uang yang bisa dicuri Burbir