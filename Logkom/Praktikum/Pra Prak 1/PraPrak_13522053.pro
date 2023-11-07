/* Nama : Erdianti Wiga Putri Andini */
/* NIM : 13522053 */
/* Kelas : K-01 */

/* ******************************************************************** */
                /* BAGIAN I : Fakta, Rule, dan Query */
/* ******************************************************************** */

/* Deklarasi Fakta */
/* pria(X) : X adalah pria */
pria(athif).
pria(dillon).
pria(henri).
pria(michael).
pria(hanif).
pria(robert).
pria(bagas).
pria(fio).
pria(daniel).
pria(rupert).

/* wanita(X) : X adalah wanita */
wanita(joli).
wanita(elysia).
wanita(margot).
wanita(jena).
wanita(jeni).
wanita(ana).
wanita(emma).

/* usia(X,Y) : X berusia Y */
usia(athif, 60).
usia(dillon, 63).
usia(henri, 48).
usia(michael, 28).
usia(hanif, 47).
usia(robert, 32).
usia(bagas, 29).
usia(fio, 30).
usia(daniel, 7).
usia(rupert, 6).
usia(joli, 58).
usia(elysia, 500).
usia(margot, 43).
usia(jena, 27).
usia(jeni, 28).
usia(ana, 23).
usia(emma, 6).

/* menikah(X,Y) : X menikah dengan Y */
menikah(athif, joli).
menikah(joli, athif).
menikah(dillon, elysia).
menikah(elysia, dillon).
menikah(henri, margot).
menikah(margot, henri).
menikah(fio, jena).
menikah(jena, fio).
menikah(fio, jeni).
menikah(jeni, fio).

/* anak(X,Y) : X adalah anak Y */
anak(margot, athif).
anak(margot, joli).
anak(michael, athif).
anak(michael, joli).
anak(hanif, dillon).
anak(hanif, elysia).
anak(robert, henri).
anak(robert, margot).
anak(bagas, henri).
anak(bagas, margot).
anak(jena, henri).
anak(jena, margot).
anak(jeni, hanif).
anak(ana, hanif).
anak(emma, jeni).
anak(emma, fio).
anak(daniel, fio).
anak(daniel, jena).
anak(rupert, fio).
anak(rupert, jena).


/* Deklarasi Rules */
/* saudara(X,Y) : X adalah saudara kandung maupun tiri dari Y */
saudara(X,Y) :-
    anak(U,V),
    anak(W,Z),
    Z is V.

/* saudaratiri(X,Y) : X adalah saudara tiri dari Y */
saudaratiri(X,Y) :-
    saudara(U,W),
    V \== Z.
    anak(U,V),
    anak(W,Z),

/* kakak(X,Y) : X adalah kakak dari Y (kakak kandung maupun tiri) */
kakak(X,Y) :- 
    saudara(X,Y),
    usia(X,U),
    usia(Y,V),
    U > V.

/* keponakan(X,Y) : X adalah keponakan dari Y */
keponakan(X,Y) :- 
    anak(X,U),
    saudara(U,Y).

/* mertua(X,Y) : X adalah mertua dari Y */
mertua(X,Y) :-
    menikah(X,U),
    anak(U,Y).

/* nenek(X,Y) : X adalah nenek dari Y */
nenek(X,Y) :-
    wanita(X),
    anak(U,X),
    anak(Y,U).

/* keturunan(X,Y) : X adalah keturunan dari Y (anak, cucu, dan seterusnya) */
keturunan(X,Y) :- anak(X,Y).
keturunan(X,Y) :- nenek(Y,X).
keturunan(X,Y) :- anak(X,U), keturunan(U,Y).

/* lajang(X) : X adalah orang yang tidak menikah */
lajang(X) :-
    \== menikah(X,_).

/* anakbungsu(X) : X adalah anak paling muda */
anakbungsu(X) :-
    anak(X,Y),
    \== kakak(X,_).

/* yatimpiatu(X) : X adalah orang yang orang tuanya tidak terdefinisi */
yatimpiatu :-
    \== anak(X,_).


/* ******************************************************************** */
                    /* BAGIAN II : Rekursivitas */
/* ******************************************************************** */

/* 1. Exponent
A (Nilai A > 0) merupakan basis perpangkatan, 
sedangkan B merupakan pangkat dari A (Nilai B ≥ 0). 
exponent(A, B, X) akan mengeluarkan hasil perpangkatan AB yaitu X. */
exponent(_,0,1) :- !.
exponent(A,B,X) :-
    B1 is B-1, 
    exponent(A,B1,X1), 
    X is A*X1.

/* 2. Population
Walikota Los Bandung ingin mengetahui pertumbuhan populasi di kotanya dalam T tahun (Nilai  T ≥ 0). 
Pada awalnya (tahun ke-0), kota Los Bandung memiliki populasi awal P (Nilai P > 0). 
Pada setiap tahunnya, populasi kota Los Bandung akan bertambah banyak dengan rasio R (Nilai R > 1). 
Suatu nilai C (Nilai C ≥ 0 dan < P) merupakan nilai khusus yang menggambarkan dinamika penduduk kota awal. 
Nilai C akan bertambah sebesar 1 setiap tahunnya. 
Pada tahun ganjil,  jumlah penduduk (setelah bertambah dengan rasio R) akan bertambah sebanyak C. 
Sementara pada tahun genap, jumlah penduduk berkurang sebanyak C. 
population(P, R, T, C, X) akan menghasilkan jumlah penduduk pada tahun T, yaitu X. */
main2 :- population(3,2,5,0,Y), write(Y).
population(P, R, 0, _, P) :- !.
population(P, R, T, C, X) :-
    T > 0,
    T1 is T-1.
    T mod 2 =:= 0, population(P, R, T1, C, X1), X1 is P-C,
    T mod 2 =\= 0, population(P, R, T1, C, X1), X1 is P+R+C,
    X is X1.

/* 3. Perrin 
Perrin sequence merupakan suatu barisan angka sebagai berikut:
3, 0, 2, 3, 2, 5, 5, 7, 10, 12, 17, 22, 29, 39, 51, 68, ...
Perrin sequence sering kali disebut sebagai “skipponaci”, dimana suku ke-3 dihasilkan dari penjumlahan suku ke-1 dan ke-0, dan seterusnya. 
perrin(N, X) akan mengembalikan nilai dari suku ke-N pada Perrin sequence, yaitu X. Nilai N dimulai dari 0 */
perrin(0,3).
perrin(1,0).
perrin(2,2).
perrin(N,X) :-
    N > 2,
    N1 is N-2,
    perrin(N1,X1),
    N2 is N1-1,
    perrin(N2,X2),
    X is X1 + X2.

/* 4. HCF
hcf(A, B, X) akan mengeluarkan hasil X yaitu highest common factor dari A dan B. */
hcf(A,B,X) :-
    A = B,
    X is A.
hcf(A,B,X) :-
    A > B,
    A1 is A-B,
    hcf(A1,B,X).
hcf(A,B,X) :-
    B > A,
    B1 is B-A,
    hcf(A,B1,X).

/* 5. Make Pattern 
makePattern(N) akan menuliskan sebuah persegi angka sebesar N satuan 
dengan setiap angkanya menyatakan kedalaman persegi. */
main :- makePattern(5).
makePattern(N) :-
    makePatternHelper(N, N).
makePatternHelper(N, 0) :- !.
makePatternHelper(N, Row) :-
    Row > 0,
    printRow(N, Row),
    NextRow is Row - 1,
    makePatternHelper(N, NextRow).
printRow(N, Row) :-
    printRow(N, Row, Row).
printRow(N, CurrentRow, 0) :- !, nl.
printRow(N, CurrentRow, Col) :-
    Col > 0,
    write(CurrentRow),
    write(' '),
    NextCol is Col - 1,
    printRow(N, CurrentRow, NextCol).
